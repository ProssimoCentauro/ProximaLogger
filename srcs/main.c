#include "../includes/proxima_logger.h"
#include <stdlib.h>
int	main()
{
	Logger *logger = (Logger *)calloc(1, sizeof(Logger));


	logger->output_stream = stdout;
	logger->level = DEBUG;

	log_write(logger, DEBUG, __FILE__, __LINE__, __func__, "pippo %s\n", "franco");
	return (0);
}
