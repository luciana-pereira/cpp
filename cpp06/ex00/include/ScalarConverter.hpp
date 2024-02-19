/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:49:36 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/19 01:20:48 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <cmath>
#include <stdexcept>    // For invalid_argument, out_of_range
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <cstdlib>   // para strtol, atol
#include <limits>    // para std::numeric_limits
class ScalarConverter {
public:
	// ScalarConverter(void);
	// ~ScalarConverter(void);
	static void	convert(std::string& literal);
};

#endif
