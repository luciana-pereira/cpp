/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:10:37 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/04 23:14:07 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

int	main(void) {
	const int		intArray[] = {1, 2, 3, 4, 5};
	const char		charArray[] = {'a', 'b', 'c', 'd', 'e'};
	const double	doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

	std::cout << "Integer Array: ";
	iter<int>(intArray, 5, printElement<int>);
	std::cout << std::endl;

	std::cout << "Char Array: ";
	iter<char>(charArray, 5, printElement<char>);
	std::cout << std::endl;

	std::cout << "Double Array: ";
	iter<double>(doubleArray, 5, printElement<const double>);
	std::cout << std::endl;

    return (0);
}
