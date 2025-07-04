#include "../includes/proxima_logger.h"

void print_timestamp(FILE *output_stream)
{
    time_t now = time(NULL);
    struct tm *local = localtime(&now);

    if (!local || !output_stream)
        return;

    fprintf(output_stream, "[%02d/%02d/%d %02d:%02d:%02d] ",
            local->tm_mday,
            local->tm_mon + 1,
            local->tm_year + 1900,
            local->tm_hour,
            local->tm_min,
            local->tm_sec);
}

void log_write(Logger *logger, LogLevel level,
               const char *file, int line,
               const char *func, const char *fmt, ...)
{
    if (!logger || !logger->output_stream || level < logger->level)
    {
        printf("nope\n");
        return;
    }

    FILE *out = logger->output_stream;
    va_list args;
    va_start(args, fmt);

	if (logger->enable_timestap)
		print_timestamp(out);
    
	if (logger->enable_file_info)
		fprintf(out, "%s:%d %s: ", file, line, func);
    
	vfprintf(out, fmt, args);
    
	va_end(args);
}

