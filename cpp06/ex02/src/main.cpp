/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:45:00 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/04 01:50:10 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"

int	main(void) {
	std::srand(time(0));
	
	std::cout << std::endl;
	for (int index = 0; index < 3; index++) {
		Base* instance = generate();
		Base& reference = *instance;

		std::cout << "IDENTIFY POINTER: ";
		identify(instance);
		std::cout << "IDENTIFY REFERENCE: ";
		identify(reference);
		
		delete instance;
	}
	std::cout << std::endl;

	return (0);
}
