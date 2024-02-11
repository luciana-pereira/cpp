#include "../include/Harl.hpp"
#include <cctype>

int	main(int argc, char *argv[])
{
	Harl		harl;
	int	options;

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <log_level>" << std::endl;
		return (-1);
	}
	std::string validLevels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	options = -1;
	std::string logLevel(argv[1]);
	for (size_t index = 0; index < logLevel.length(); ++index)
	{
		logLevel[index] = std::toupper(logLevel[index]);
	}
	for (int i = 0; i < 4; i++)
	{
		if (std::string(logLevel) == validLevels[i])
			options = i;
    }
	// harl.complain(logLevel);
	Harl	filter;
	switch (options)
	{
		case DEBUG:
			filter.complain("DEBUG");
			filter.complain("INFO");
			filter.complain("WARNING");
			filter.complain("ERROR");
			break ;
		case INFO:
			filter.complain("INFO");
			filter.complain("WARNING");
			filter.complain("ERROR");
			break ;
		case WARNING:
			filter.complain("WARNING");
			filter.complain("ERROR");
			break ;
		case ERROR:
			filter.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
	return (0);
}
