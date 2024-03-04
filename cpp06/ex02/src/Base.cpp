/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:36:00 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/04 01:48:33 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"

Base*	generate() {
	int	randomValue = rand() % 3;

	switch (randomValue) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
		default: return (NULL);
	}
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

void identify(Base& p) {
	if (dynamic_cast<A*>(&p) != NULL) {
		std::cout << "A" << std::endl;
		return ;
	}

	if (dynamic_cast<B*>(&p) != NULL) {
		std::cout << "B" << std::endl;
		return ;
	}

	if (dynamic_cast<C*>(&p) != NULL) {
		std::cout << "C" << std::endl;
		return ;
	}

	std::cout << "Unknown type" << std::endl;
}

