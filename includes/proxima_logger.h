#ifndef PROXIMA_LOGGER_H
#define PROXIMA_LOGGER_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
	DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL
} LogLevel;

typedef struct {
	unsigned char *name;
    FILE *output_stream;
    LogLevel level;
    bool enable_timestamp;
    bool enable_colors;
    bool enable_file_info;
    pthread_mutex_t lock;
} Logger;


void log_write(Logger *logger, LogLevel level, const char *file, int line, const char *func, const char *fmt, ...);

#endif
