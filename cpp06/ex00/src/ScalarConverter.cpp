/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:47:02 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/03 20:45:24 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include "../include/ScalarConverterFunctionsUtils.hpp"

void	ScalarConverter::convert(std::string& literal) {
	InputType type = detectType(literal);
	displayConversion(literal, type);
}
