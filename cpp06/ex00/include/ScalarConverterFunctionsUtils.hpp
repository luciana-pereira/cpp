/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterFunctionsUtils.hpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:33:23 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/03 21:31:48 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_FUNCTIONS_UTILS_HPP
# define SCALAR_CONVERTER_FUNCTIONS_UTILS_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>


typedef enum InputType 
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	UNKNOWN,
	NON
} InputType;

void		handlePseudoLiterals(const std::string &literal);
void		convertDouble(const std::string &literal);
void		convertFloat(const std::string &literal);
void		convertInt(const std::string &literal);
void		convertChar(const std::string &literal);
void		displayConversion(const std::string& literal, InputType type);
bool		containsNonPrintable(const std::string &literal);
InputType	detectType(const std::string &literal);

#endif
