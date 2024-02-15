/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 01:07:15 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/13 02:27:56 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
	std::cout << this->getType() << " constructor" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal(other), _brain(new Brain(*other._brain))
{
	std::cout << other.getType() << " copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << other.getType() << " copy assignment operator" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << this->getType() << " destructor" << std::endl;
	delete _brain;
	_brain = NULL;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow! Meow!" << std::endl;
}

std::ostream&	operator<<(std::ostream &stream, const Cat &other)
{
	stream << "Type: " << other.getType() << std::endl;
	return (stream);
}
