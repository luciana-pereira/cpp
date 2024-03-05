/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:34:12 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/04 20:57:47 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/whatever.hpp"

int	main(void) {
	int	a = 5;
	int	b = 10;
	
	std::cout << std::endl;
	std::cout << "======== TESTING SWAP FUNCTION ========" << std::endl;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

	std::cout << "======== TESTING MIN FUNCTION ========" << std::endl;
	int minResult = min(a, b);
	std::cout << "Min value: " << minResult << std::endl;

	std::cout << "======== TESTING MAX FUNCTION ========" << std::endl;
	int maxResult = max(a, b);
	std::cout << "Max value: " << maxResult << std::endl;
	std::cout << std::endl;

	return (0);
}
