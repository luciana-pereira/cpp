/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 02:22:09 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/13 02:23:49 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << "AAnimal constructor" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "AAnimal " << this->_type << " constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type)
{
	std::cout << "AAnimal copy constructor" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal copy assignment operator" << std::endl;
	if (this != &other)
	{
		_type = other.getType();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream &stream, const AAnimal &other)
{
	stream << "Type: " << other.getType() << std::endl;
	return (stream);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal " << this->_type << " destructor" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (_type);
}
