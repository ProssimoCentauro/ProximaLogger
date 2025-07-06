
#ifndef PROXIMA_LOGGER_H
#define PROXIMA_LOGGER_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Reset
#define RESET			"\x1b[0m"

// Bold colors (Bright)
#define BOLD_BLACK		"\x1b[1;30m"
#define BOLD_RED		"\x1b[1;31m"
#define BOLD_GREEN		"\x1b[1;32m"
#define BOLD_YELLOW		"\x1b[1;33m"
#define BOLD_BLUE		"\x1b[1;34m"
#define BOLD_MAGENTA	"\x1b[1;35m"
#define BOLD_CYAN		"\x1b[1;36m"
#define BOLD_WHITE		"\x1b[1;37m"
//#define BOLD_GREY		"\x1b[1;100m"
#define BOLD_GREY "\x1b[1;38;5;245m"  // grigio medio

#define LOG_DEBUG(logger, ...) \
    log_write(logger, DEBUG, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define LOG_INFO(logger, ...) \
    log_write(logger, INFO, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define LOG_WARN(logger, ...) \
    log_write(logger, WARNING, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define LOG_ERROR(logger, ...) \
    log_write(logger, ERROR, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define LOG_FATAL(logger, ...) \
    log_write(logger, FATAL, __FILE__, __LINE__, __func__, __VA_ARGS__)

typedef enum {
	DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL
} LogLevel;

typedef struct {
	const unsigned char *name;
    FILE *output_stream;
    LogLevel level;
    bool enable_timestamp;
    bool enable_colors;
    bool enable_file_info;
} Logger;


void log_write(Logger *logger, LogLevel level, const char *file, int line, const char *func, const char *fmt, ...);
Logger	*create_logger(unsigned char *name, FILE *out, LogLevel level, bool enable_timestamp, bool enable_colors, bool enable_file_info);
Logger	*create_default_logger( void );

#endif
