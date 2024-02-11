#include "../include/Harl.hpp"
#include <cctype>

int	main(int argc, char *argv[])
{
	Harl		harl;

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <log_level>" << std::endl;
		return (1);
	}
	std::string logLevel(argv[1]);
	for (size_t index = 0; index < logLevel.length(); ++index)
	{
		logLevel[index] = std::tolower(logLevel[index]);
	}
	harl.complain(logLevel);
	return (0);
}
