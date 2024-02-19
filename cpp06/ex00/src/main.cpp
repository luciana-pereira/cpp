/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:04:12 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/19 01:33:52 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	std::cout << std::endl;
	std::cout << "=== START OF TESTS ===" << std::endl;
	std::cout << std::endl;

	std::cout << " Valid literals:" << std::endl;
	std::cout << std::endl;

	std::cout << "./convert 0" << std::endl;
	std::string literal2 = "0";
	ScalarConverter::convert(literal2);
	std::cout << std::endl;

	std::cout << "./convert 0.0f" << std::endl;
	std::string literal22 = "0.0f";
	ScalarConverter::convert(literal22);
	std::cout << std::endl;

	std::cout << "./convert c" << std::endl;
	std::string literal23 = "c";
	ScalarConverter::convert(literal23);
	std::cout << std::endl;

	std::cout << "./convert abc" << std::endl;
	std::string literal24 = "abc";
	ScalarConverter::convert(literal24);
	std::cout << std::endl;

	std::cout << "\n./convert 42.0f" << std::endl;
	std::string literal25 = "42.0f";
	ScalarConverter::convert(literal25);
	std::cout << std::endl;

	std::cout << "\n./convert -42.42f" << std::endl;
	std::string literal6 = "-42.42f";
	ScalarConverter::convert(literal6);
	std::cout << std::endl;

	std::cout << "\n./convert +42.42f" << std::endl;
	std::string literal7 = "+42.42f";
	ScalarConverter::convert(literal7);
	std::cout << std::endl;

	std::cout << "\n./convert -" << std::endl;
	std::string literal8 = "-";
	ScalarConverter::convert(literal8);
	std::cout << std::endl;

	std::cout << "\n./convert +" << std::endl;
	std::string literal9 = "+";
	ScalarConverter::convert(literal9);
	std::cout << std::endl;

	std::cout << "\n./convert *" << std::endl;
	std::string literal10 = "*";
	ScalarConverter::convert(literal10);
	std::cout << std::endl;

	std::cout << "======================" << std::endl;

	std::cout << "\nPseudo literals:" << std::endl;
	std::cout << std::endl;

	std::cout << "./convert -inff" << std::endl;
	std::string literal11 = "-inff";
	ScalarConverter::convert(literal11);
	std::cout << std::endl;

	std::cout << "\n./convert +inff" << std::endl;
	std::string literal12 = "+inff";
	ScalarConverter::convert(literal12);
	std::cout << std::endl;

	std::cout << "\n./convert nanf" << std::endl;
	std::string literal13 = "nanf";
	ScalarConverter::convert(literal13);
	std::cout << std::endl;

	std::cout << "\n./convert -inf" << std::endl;
	std::string literal14 = "-inf";
	ScalarConverter::convert(literal14);
	std::cout << std::endl;

	std::cout << "\n./convert +inf" << std::endl;
	std::string literal15 = "+inf";
	ScalarConverter::convert(literal15);
	std::cout << std::endl;

	std::cout << "\n./convert nan" << std::endl;
	std::string literal16 = "nan";
	ScalarConverter::convert(literal16);
	std::cout << std::endl;

	std::cout << "======================" << std::endl;

	std::cout << "\nInvalid literals:" << std::endl;
	std::cout << std::endl;

	std::cout << "\n./convert \t " << std::endl;
	std::string literal17 = "\t";
	ScalarConverter::convert(literal17);
	std::cout << std::endl;

	std::cout << "\n./convert 1.2.3" << std::endl;
	std::string literal18 = "1.2.3";
	ScalarConverter::convert(literal18);
	std::cout << std::endl;

	std::cout << "======================" << std::endl;
    return (0);
}
