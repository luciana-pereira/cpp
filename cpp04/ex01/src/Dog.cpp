/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 01:00:38 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/13 00:19:23 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << this->getType() << " constructor" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << other.getType() << " copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << other.getType() << " copy assignment operator" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete	_brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << this->getType() << " destructor" << std::endl;
	delete _brain;
	_brain = NULL;
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
