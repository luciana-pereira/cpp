/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 01:07:15 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/12 16:32:53 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat constructor" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << other.getType() << " copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << other.getType() << "Cat copy assignment operator" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << this->getType() << " destructor" << std::endl;
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
