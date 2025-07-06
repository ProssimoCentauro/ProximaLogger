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


const char *get_color(LogLevel level)
{
    switch (level)
	{
        case DEBUG:		return BOLD_GREY;
        case INFO:		return BOLD_GREEN;
        case WARNING:	return BOLD_YELLOW;
        case ERROR:		return BOLD_RED;
        case FATAL:		return BOLD_MAGENTA;
        default:       return RESET;
    }
}

const char *get_level(LogLevel level)
{
    switch (level)
	{
        case DEBUG:		return "DEBUG";
        case INFO:		return "INFO";
        case WARNING:	return "WARNING";
        case ERROR:		return "ERROR";
        case FATAL:		return "FATAL";
        default:       return "";
    }
}


void print_log_level(FILE *out, LogLevel level)
{
	switch (level)
	{
		case DEBUG:		fprintf(out, "DEBUG"); break;
        case INFO:		fprintf(out, "INFO"); break;
        case WARNING:	fprintf(out, "WARNING"); break;
        case ERROR:		fprintf(out, "ERROR"); break;
		case FATAL:		fprintf(out, "FATAL"); break;
        default:       return;
	}
}

void uncolored_log(Logger *logger, LogLevel level,
               const char *file, int line,
               const char *func, const char *fmt,
			   va_list args)
{
    FILE *out = logger->output_stream;

	fprintf(out, "LOG %s ", get_level(level));
	fprintf(out, "{%s} ",logger->name);

	if (logger->enable_timestamp)
		print_timestamp(out);
	
	if (logger->enable_file_info)
		fprintf(out, "%s:%d %s: ", file, line, func);
	
	vfprintf(out, fmt, args);
}

void colored_log(Logger *logger, LogLevel level,
               const char *file, int line,
               const char *func, const char *fmt,
			   va_list args)
{
    FILE *out = logger->output_stream;
	const char *log_color = get_color(level);

	fprintf(out, "%sLOG %s "RESET, log_color, get_level(level));
	fprintf(out, "%s{"RESET"%s%s} ", log_color, logger->name, log_color);

	if (logger->enable_timestamp)
	{
		fprintf(out, "%s", log_color);
		print_timestamp(out);
		fprintf(out, RESET);
	}
	if (logger->enable_file_info)
	{
		fprintf(out, "%s%s:"RESET"%d %s%s: "RESET, file, log_color, line, func, log_color);
	}

	vfprintf(out, fmt, args);
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

	va_list	args;
	va_start(args, fmt);
	if (logger->enable_colors)
		colored_log(logger, level, file, line, func, fmt, args);
	else
		uncolored_log(logger, level, file, line, func, fmt, args);
	va_end(args);
}
