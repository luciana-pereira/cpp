/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 01:00:38 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/12 22:41:28 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << this->getType() << " constructor" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << other.getType() << " copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << other.getType() << " copy assignment operator" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << this->getType() << " destructor" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof! Woof!" << std::endl;
}

std::ostream&	operator<<(std::ostream &stream, const Dog &other)
{
	stream << "Type: " << other.getType() << std::endl;
	return (stream);
}
