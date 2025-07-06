#include "proxima_logger.h"

Logger	*create_logger(unsigned char *name,
		FILE *out,
		LogLevel level,
		bool enable_timestamp,
		bool enable_colors,
		bool enable_file_info)
{
	Logger *logger = (Logger *)calloc(1, sizeof(Logger));
	if (!logger)
		return (NULL);
	logger->name = name;
	logger->output_stream = out;
	logger->level = level;
	logger->enable_timestamp = enable_timestamp;
	logger->enable_colors = enable_colors;
	logger->enable_file_info = enable_file_info;
	return (logger);
}

Logger	*create_default_logger( void )
{
	Logger *logger = (Logger *)calloc(1, sizeof(Logger));
	if (!logger)
		return (NULL);
	logger->name = (unsigned char *)"UnnamedLogger";
	logger->output_stream = stdout;
	logger->level = DEBUG;
	logger->enable_timestamp = true;
	logger->enable_colors = true;
	logger->enable_file_info = true;
	return (logger);
}
