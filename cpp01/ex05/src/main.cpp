/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 01:30:51 by lucperei          #+#    #+#             */
/*   Updated: 2024/04/15 01:30:54 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"
#include <cctype>

int main(int argc, char *argv[])
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
	
    // Conversão do argumento para letras maiúsculas
    for (size_t index = 0; index < logLevel.length(); ++index)
    {
        logLevel[index] = std::toupper(logLevel[index]);
    }
    // Verificação do nível de log
    for (int i = 0; i < 4; i++)
    {
        if (std::string(logLevel) == validLevels[i])
        {
            isInvalidArg = false;
            filter.complain(validLevels[i]);
            break;
        }
    }
// Tratamento de argumentos inválidos
    if (isInvalidArg)
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

    return 0;
}
