/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterFunctionsUtils.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:26:17 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/25 03:32:31 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverterFunctionsUtils.hpp"

InputType	detectLiteralType(const std::string &input) {
	const std::string pseudoLiterals[6] = {
        "-inff", "+inff", "nanf", "-inf", "+inf", "nan"
    };

	for (size_t index = 0; index < 6; ++index) {
		if (input == pseudoLiterals[index]) {
			if (index < 3)
				return ((index % 2 == 0) ? NEGATIVE_INF : POSITIVE_INF);
			else
				return ((index % 2 == 0) ? NAN : UNKNOWN);
		}
	}
	return (UNKNOWN);
}
