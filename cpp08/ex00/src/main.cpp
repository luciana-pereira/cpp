/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 04:01:09 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/05 04:11:04 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"

int	main(void) {
	try {
		std::vector<int> myVector;

		for (int i = 0; i < 5; i++) {
			myVector.push_back(i);
		}

		int valueToFind = 3;
		std::vector<int>::iterator result = easyfind(myVector, valueToFind);
		std::cout << "Value " << valueToFind << " found at position " << std::distance(myVector.begin(), result) << std::endl;

		valueToFind = 8;
		result = easyfind(myVector, valueToFind);
		std::cout << "Value " << valueToFind << " found at position " << std::distance(myVector.begin(), result) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
