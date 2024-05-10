/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:46:23 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/12 17:33:46 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal " << this->_type << " constructor" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << "Animal copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment operator" << std::endl;
	if (this != &other)
	{
		_type = other.getType();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream &stream, Animal const &other)
{
	stream << "Type: " << other.getType() << std::endl;
	return (stream);
}

Animal::~Animal(void)
{
	std::cout << "Animal " << this->_type << " destructor" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal sound ..." << std::endl;
}
