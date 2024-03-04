/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:04:12 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/03 20:43:08 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	std::cout << std::endl;
	std::cout << "==== START OF TESTS ====" << std::endl;
	std::cout << std::endl;

	std::cout << "==== CHAR LITERALS ====" << std::endl;
	
	std::cout << "./convert c" << std::endl;
	std::string literal1 = "c";
	ScalarConverter::convert(literal1);
	std::cout << std::endl;

	std::cout << "./convert a" << std::endl;
	std::string literal2 = "a";
	ScalarConverter::convert(literal2);
	std::cout << std::endl;

	std::cout << "==== INT LITERALS ====" << std::endl;
	
	std::cout << "./convert 0" << std::endl;
	std::string literal3 = "0";
	ScalarConverter::convert(literal3);
	std::cout << std::endl;

	std::cout << "./convert -42" << std::endl;
	std::string literal4 = "-42";
	ScalarConverter::convert(literal4);
	std::cout << std::endl;

	std::cout << "./convert 42" << std::endl;
	std::string literal5 = "42";
	ScalarConverter::convert(literal5);
	std::cout << std::endl;

	std::cout << "==== FLOAT LITERALS ====" << std::endl;

	std::cout << "./convert 0.0f" << std::endl;
	std::string literal6 = "0.0f";
	ScalarConverter::convert(literal6);
	std::cout << std::endl;

	std::cout << "./convert -4.2f" << std::endl;
	std::string literal7 = "-4.2f";
	ScalarConverter::convert(literal7);
	std::cout << std::endl;
	
	std::cout << "./convert 4.2f" << std::endl;
	std::string literal8 = "4.2f";
	ScalarConverter::convert(literal8);
	std::cout << std::endl;
	
	std::cout << "./convert 42.0f" << std::endl;
	std::string literal9 = "42.0f";
	ScalarConverter::convert(literal9);
	std::cout << std::endl;

	std::cout << "==== DOUBLE LITERALS ====" << std::endl;

	std::cout << "./convert 0.0" << std::endl;
	std::string literal10 = "0.0";
	ScalarConverter::convert(literal10);
	std::cout << std::endl;

	std::cout << "./convert -4.2" << std::endl;
	std::string literal11 = "-4.2";
	ScalarConverter::convert(literal11);
	std::cout << std::endl;

	std::cout << "./convert 4.2" << std::endl;
	std::string literal12 = "4.2";
	ScalarConverter::convert(literal12);
	std::cout << std::endl;

	std::cout << "==== PSEUDO LITERALS ====" << std::endl;
	std::cout << "Pseudo literals:" << std::endl;
	std::cout << std::endl;

	std::cout << "./convert -inff" << std::endl;
	std::string literal13 = "-inff";
	ScalarConverter::convert(literal13);
	std::cout << std::endl;

	std::cout << "./convert +inff" << std::endl;
	std::string literal14 = "+inff";
	ScalarConverter::convert(literal14);
	std::cout << std::endl;

	std::cout << "./convert nanf" << std::endl;
	std::string literal15 = "nanf";
	ScalarConverter::convert(literal15);
	std::cout << std::endl;

	std::cout << "./convert -inf" << std::endl;
	std::string literal16 = "-inf";
	ScalarConverter::convert(literal16);
	std::cout << std::endl;

	std::cout << "./convert +inf" << std::endl;
	std::string literal17 = "+inf";
	ScalarConverter::convert(literal17);
	std::cout << std::endl;

	std::cout << "./convert nan" << std::endl;
	std::string literal18 = "nan";
	ScalarConverter::convert(literal18);
	std::cout << std::endl;

	std::cout << "==== NON PRINTABLE ====" << std::endl;

	std::cout << "./convert \t " << std::endl;
	std::string literal19 = "\t";
	ScalarConverter::convert(literal19);
	std::cout << std::endl;

	std::cout << "./convert \a" << std::endl;
	std::string literal20 = "\a";
	ScalarConverter::convert(literal20);
	std::cout << std::endl;

	std::cout << "======================" << std::endl;
    return (0);
}
