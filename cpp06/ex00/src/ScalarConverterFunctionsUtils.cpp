/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterFunctionsUtils.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:26:17 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/03 21:05:49 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverterFunctionsUtils.hpp"

InputType	detectType(const std::string &literal) {
	bool hasF = false;
	bool hasDot = false;
	bool isNumber = true;
	bool isNegative = false;

	for (size_t i = 0; i < literal.length(); ++i) {
		if (i == 0 && literal[i] == '-') {
			isNegative = true;
		} else if (literal[i] == '.') {
			if (hasDot || hasF) {
				isNumber = false;
				break ;
			}
			hasDot = true;
		} else if (literal[i] == 'f') {
			if (hasF || i != literal.length() - 1) {
				isNumber = false;
				break ;
			}
			hasF = true;
		} else if (!std::isdigit(literal[i])) {
			isNumber = false;
			break ;
		}
	}

	if (isNumber) {
		if (hasDot || hasF) {
			return ((hasF) ? FLOAT : DOUBLE);
		} else {
			return ((isNegative) ? CHAR : INT);
		}
	} else {
		if (literal == "nan" || literal == "nanf" || literal == "+inf" 
			|| literal == "+inff" || literal == "-inf" || literal == "-inff") {
			return (PSEUDO);
		}

		if (containsNonPrintable(literal)) {
			return (NON);
		}

		if ((literal.length() == 1 && literal[0] == '-') || (literal.length() == 1 && !std::isdigit(literal[0]) && !containsNonPrintable(literal))) {
			return (CHAR);
		}
		return (UNKNOWN);
	}
}

bool	containsNonPrintable(const std::string &literal) {
	const char* nonPrintableChars[5] = {
		"\t", "\n", "\r", "\v", "\f"
	};
	
    for (size_t i = 0; i < literal.length(); ++i) {
        if (literal[i] < 32 || literal[i] >= 127) {
            return (true);
        }
    }
	
	for (size_t i = 0; i < sizeof(nonPrintableChars) / sizeof(nonPrintableChars[0]); ++i) {
		if (literal.find(nonPrintableChars[i]) != std::string::npos) {
			return (true);
			break ;
		}
	}
	return (false);
}

void	displayConversion(const std::string& literal, InputType type) {
	switch (type) {
		case CHAR: {
			convertChar(literal);
			break ;
		}
		case INT: {
			convertInt(literal);
			break ;
		}
		case FLOAT: {
			convertFloat(literal);
			break ;
		}
		case DOUBLE: {
			convertDouble(literal);
			break ;
		}
		case PSEUDO: {
			handlePseudoLiterals(literal);
			break ;
		}
		case NON: {
			std::cout << "Error: Character cannot be displayed" << std::endl;
			break ;
		}
		default:
			std::cout << "Unknown type or not convertible." << std::endl;
	}
}

void	convertChar(const std::string &literal) {
	char convertedChar = literal[0];
		
	if ((static_cast<int>(convertedChar) < 0) || (static_cast<int>(convertedChar) > 127)) {
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(static_cast<char>(convertedChar))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << convertedChar << "'" << std::endl;
	}
	
	if ((std::atol(literal.c_str()) < std::numeric_limits<int>::min())
		|| (std::atol(literal.c_str()) > std::numeric_limits<int>::max())) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(convertedChar) << std::endl;
	}
		
	if ((static_cast<float>(convertedChar) < -std::numeric_limits<float>::max())
		|| (static_cast<float>(convertedChar) > std::numeric_limits<float>::max())) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(convertedChar) << "f" << std::endl;
	}
	
	if ((static_cast<double>(convertedChar) < -std::numeric_limits<double>::max())
		|| (static_cast<double>(convertedChar) > std::numeric_limits<double>::max())) {
		std::cout << "double: impossible" << std::endl;
	} else {
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(convertedChar) << std::endl;
	}
}

void	convertInt(const std::string &literal) {
	int convertedInt = std::atoi(literal.c_str());
	
	if (static_cast<int>(convertedInt) < 0 || static_cast<int>(convertedInt) > 127) {
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(static_cast<char>(convertedInt))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(convertedInt) << "'" << std::endl;
	}
	
	if (std::atol(literal.c_str()) < std::numeric_limits<int>::min()
		|| std::atol(literal.c_str()) > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << convertedInt << std::endl;
	}
	
	if (static_cast<float>(convertedInt) < -std::numeric_limits<float>::max()
		|| static_cast<float>(convertedInt) > std::numeric_limits<float>::max()) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(convertedInt) << "f" << std::endl;
	}
	
	if (static_cast<double>(convertedInt) < -std::numeric_limits<double>::max()
		|| static_cast<double>(convertedInt) > std::numeric_limits<double>::max()) {
		std::cout << "double: impossible" << std::endl;
	} else {
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(convertedInt) << std::endl;
	}
}

void	convertFloat(const std::string &literal) {
	float	convertedFloat = std::atof(literal.c_str());
	
	if (static_cast<int>(convertedFloat) < 0 
		|| static_cast<int>(convertedFloat) > 127) {
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(static_cast<char>(convertedFloat))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(convertedFloat) << "'" << std::endl;
	}
		
	if (std::atol(literal.c_str()) < std::numeric_limits<int>::min()
		|| std::atol(literal.c_str()) > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(convertedFloat) << std::endl;
	}
		
	if (convertedFloat < -std::numeric_limits<float>::max()
		|| convertedFloat > std::numeric_limits<float>::max()) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << convertedFloat << "f" << std::endl;
	}
	
	if (static_cast<double>(convertedFloat) < -std::numeric_limits<double>::max()
		|| static_cast<double>(convertedFloat) > std::numeric_limits<double>::max()) {
		std::cout << "double: impossible" << std::endl;
	} else {
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(convertedFloat) << std::endl;
	}
}

void	convertDouble(const std::string &literal) {
	double convertedDouble = std::atof(literal.c_str()); 
	
	if (static_cast<int>(convertedDouble) < 0 || static_cast<int>(convertedDouble) > 127) {
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(static_cast<char>(convertedDouble))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(convertedDouble) << "'" << std::endl;
	}
		
	if (std::atol(literal.c_str()) < std::numeric_limits<int>::min()
		|| std::atol(literal.c_str()) > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(convertedDouble) << std::endl;
	}
		
	if (static_cast<float>(convertedDouble) < -std::numeric_limits<float>::max()
		|| static_cast<float>(convertedDouble) > std::numeric_limits<float>::max()) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(convertedDouble) << "f" << std::endl;
	}
	
	if (convertedDouble < -std::numeric_limits<double>::max()
		|| convertedDouble > std::numeric_limits<double>::max()) {
		std::cout << "double: impossible" << std::endl;
	} else {
		std::cout << "double: " << std::fixed << std::setprecision(1) << convertedDouble << std::endl;
	}
}

void	handlePseudoLiterals(const std::string &literal) {
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
}
