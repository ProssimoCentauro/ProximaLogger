#include "proxima_logger.h"

void	test( Logger* logger )
{
	//log_write(logger, DEBUG, __FILE__, __LINE__, __func__, "pippo %s\n", "franco");
	LOG_DEBUG(logger, "weila! %s", "floppis!\n");
	LOG_INFO(logger, "weila! %s", "floppis!\n");
	LOG_WARN(logger, "weila! %s", "floppis!\n");
	LOG_ERROR(logger, "weila! %s", "floppis!\n");
	LOG_FATAL(logger, "weila! %s", "floppis!\n");
}

int	main()
{
	Logger *logger = create_logger("Test Logger" , stdout, DEBUG, true, true, true);

	test(logger);
	return (0);
}
