/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 01:30:51 by lucperei          #+#    #+#             */
/*   Updated: 2024/04/15 01:33:31 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"
#include <cctype>

int	main(int argc, char *argv[])
{
	Harl filter;
	bool isInvalidArg = true;

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

	std::string logLevel(argv[1]);

	for (size_t index = 0; index < logLevel.length(); ++index)
	{
		logLevel[index] = std::toupper(logLevel[index]);
	}

	for (int i = 0; i < 4; i++)
	{
		if (std::string(logLevel) == validLevels[i])
		{
			isInvalidArg = false;
			filter.complain(validLevels[i]);
			break;
		}
	}

	if (isInvalidArg)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

	return 0;
}
