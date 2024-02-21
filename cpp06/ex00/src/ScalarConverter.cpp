/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:47:02 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/19 03:46:41 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <sstream>

void ScalarConverter::convert(std::string& literal) {
    int count = 0;
    bool containsNotPrintable = false;
    std::string pseudoLiterals[6] = {
        "-inff", "+inff", "nanf", "-inf", "+inf", "nan"
    };
	
    const char* nonPrintableChars[5] = {
        "\t", "\n", "\r", "\v", "\f"
    };

    for (size_t index = 0; index < 6; index++) {
        if (literal == pseudoLiterals[index]) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            if (literal == "nan" || literal == "nanf") {
                std::cout << "float: nanf" << std::endl;
                std::cout << "double: nan" << std::endl;
            } else if (literal == "+inf" || literal == "+inff") {
                std::cout << "float: +inff" << std::endl;
                std::cout << "double: +inf" << std::endl;
            } else if (literal == "-inf" || literal == "-inff") {
                std::cout << "float: -inff" << std::endl;
                std::cout << "double: -inf" << std::endl;
            }
            return;
        }
    }

    for (size_t j = 0; j < sizeof(nonPrintableChars) / sizeof(nonPrintableChars[0]); ++j) {
        if (literal.find(nonPrintableChars[j]) != std::string::npos) {
            containsNotPrintable = true;
            break;
        }
    }

    if (literal.length() == 1 && literal[0] == '-') {
        char copyChar = literal[0];
		if (static_cast<int>(copyChar) < 0 || static_cast<int>(copyChar) > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(copyChar))
			std::cout << "char: Non displayable" << std::endl;
		else
        	std::cout << "char: '" << copyChar << "'" << std::endl;
		if (std::atol(literal.c_str()) < std::numeric_limits<int>::min()
			|| std::atol(literal.c_str()) > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else
        	std::cout << "int: " << static_cast<int>(copyChar) << std::endl;
		if (static_cast<float>(copyChar) < -std::numeric_limits<float>::max()
			|| static_cast<float>(copyChar) > std::numeric_limits<float>::max())
			std::cout << "float: impossible" << std::endl;
		else
        	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(copyChar) << "f" << std::endl;
        if (static_cast<double>(copyChar) < -std::numeric_limits<double>::max()
			|| static_cast<double>(copyChar) > std::numeric_limits<double>::max())
			std::cout << "double: impossible" << std::endl;
		else
			std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(copyChar) << std::endl;
        return ;
    }

	if (literal.length() > 1 && !std::isdigit(literal[0]) && !containsNotPrintable){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}

    if (literal.length() == 1 && !std::isdigit(literal[0]) && !containsNotPrintable) {
        char copyChar = literal[0];
		if (static_cast<int>(copyChar) < 0 || static_cast<int>(copyChar) > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(copyChar))
			std::cout << "char: Non displayable" << std::endl;
		else
        	std::cout << "char: '" << copyChar << "'" << std::endl;
		if (std::atol(literal.c_str()) < std::numeric_limits<int>::min()
			|| std::atol(literal.c_str()) > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else
        	std::cout << "int: " << static_cast<int>(copyChar) << std::endl;
		if (static_cast<float>(copyChar) < -std::numeric_limits<float>::max()
			|| static_cast<float>(copyChar) > std::numeric_limits<float>::max())
			std::cout << "float: impossible" << std::endl;
		else
        	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(copyChar) << "f" << std::endl;
        if (static_cast<double>(copyChar) < -std::numeric_limits<double>::max()
			|| static_cast<double>(copyChar) > std::numeric_limits<double>::max())
			std::cout << "double: impossible" << std::endl;
		else
			std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(copyChar) << std::endl;
        return ;
    }

    bool isNegative = (literal[0] == '-');
    if (!literal.empty() && (literal[0] == '-' || literal[0] == '+'))
    {
        literal = literal.substr(1);
    }

    bool isNumber = true;
    for (size_t i = 1; i < literal.length(); i++) {
        if (i == literal.length() - 1 && literal[i] == 'f') {
        } else if (literal[i] == '.') {
            count++;
        } else if (!std::isdigit(static_cast<char>(literal[i])) || count > 1) {
            isNumber = false;
        }
    }

    if (isNumber) {
        if (literal.find_first_of('.') != std::string::npos) {
            if (literal[literal.length() - 1] == 'f') {
                float copyFloat = std::strtof(literal.c_str(), NULL) * (isNegative ? -1 : 1);
				if (static_cast<int>(copyFloat) < 0 || static_cast<int>(copyFloat) > 127)
					std::cout << "char: impossible" << std::endl;
				else if (!std::isprint(static_cast<char>(copyFloat)))
					std::cout << "char: Non displayable" << std::endl;
				else
					std::cout << "char: '" << static_cast<char>(copyFloat) << "'" << std::endl;
				if (std::atol(literal.c_str()) < std::numeric_limits<int>::min()
					|| std::atol(literal.c_str()) > std::numeric_limits<int>::max())
					std::cout << "int: impossible" << std::endl;
				else
                	std::cout << "int: " << static_cast<int>(copyFloat) << std::endl;
				if (copyFloat < -std::numeric_limits<float>::max()
					|| copyFloat > std::numeric_limits<float>::max())
					std::cout << "float: impossible" << std::endl;
				else
					std::cout << "float: " << std::fixed << std::setprecision(1) << copyFloat << "f" << std::endl;
                if (static_cast<double>(copyFloat) < -std::numeric_limits<double>::max()
					|| static_cast<double>(copyFloat) > std::numeric_limits<double>::max())
					std::cout << "double: impossible" << std::endl;
				else
					std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(copyFloat) << std::endl;
                return;
            }
            double copyDouble = std::strtod(literal.c_str(), NULL) * (isNegative ? -1 : 1);
			if (static_cast<int>(copyDouble) < 0 || static_cast<int>(copyDouble) > 127)
				std::cout << "char: impossible" << std::endl;
			else if (!std::isprint(static_cast<char>(copyDouble)))
				std::cout << "char: Non displayable" << std::endl;
			else
            	std::cout << "char: '" << static_cast<char>(copyDouble) << "'" << std::endl;
			if (std::atol(literal.c_str()) < std::numeric_limits<int>::min()
				|| std::atol(literal.c_str()) > std::numeric_limits<int>::max())
				std::cout << "int: impossible" << std::endl;
			else
            	std::cout << "int: " << static_cast<int>(copyDouble) << std::endl;
			if (static_cast<float>(copyDouble) < -std::numeric_limits<float>::max()
				|| static_cast<float>(copyDouble) > std::numeric_limits<float>::max())
				std::cout << "float: impossible" << std::endl;
			else	
            	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(copyDouble) << "f" << std::endl;
            if (copyDouble < -std::numeric_limits<double>::max()
				|| copyDouble > std::numeric_limits<double>::max())
				std::cout << "double: impossible" << std::endl;
			else
				std::cout << "double: " << std::fixed << std::setprecision(1) << copyDouble << std::endl;
            return;
        }
        int copyInt = std::atoi(literal.c_str()) * (isNegative ? -1 : 1);
		if (static_cast<int>(copyInt) < 0 || static_cast<int>(copyInt) > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(static_cast<char>(copyInt)))
			std::cout << "char: Non displayable" << std::endl;
		else
        	std::cout << "char: '" << static_cast<char>(copyInt) << "'" << std::endl;
		if (std::atol(literal.c_str()) < std::numeric_limits<int>::min()
			|| std::atol(literal.c_str()) > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else
        	std::cout << "int: " << copyInt << std::endl;
		if (static_cast<float>(copyInt) < -std::numeric_limits<float>::max()
			|| static_cast<float>(copyInt) > std::numeric_limits<float>::max())
			std::cout << "float: impossible" << std::endl;
		else
        	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(copyInt) << "f" << std::endl;
        if (static_cast<double>(copyInt) < -std::numeric_limits<double>::max()
			|| static_cast<double>(copyInt) > std::numeric_limits<double>::max())
			std::cout << "double: impossible" << std::endl;
		else
			std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(copyInt) << std::endl;
        return;
    }

    if (containsNotPrintable) {
        std::cout << "Error: Character cannot be displayed" << std::endl;
    }
}
