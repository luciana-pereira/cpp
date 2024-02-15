/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:42:51 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/15 01:15:41 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"
#include "../include/ICharacter.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice constructor" << std::endl;
}

Ice::Ice(Ice const &m) : AMateria(m)
{
	std::cout << "Ice copy constructor" << std::endl;
	*this = m;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor" << std::endl;
}

AMateria* Ice::clone(void) const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
    // Verifica se a classe de target é realmente do tipo ICharacter
    ICharacter* character = dynamic_cast<ICharacter*>(&target);
    if (character) {
        // Se for, imprime o nome do personagem
        std::cout << "* shoots an ice bolt at " << character->getName() << std::endl;
    } else {
        // Caso contrário, imprime uma mensagem genérica
        std::cout << "* shoots an ice bolt at something *" << std::endl;
    }
}
Ice&	Ice::operator=(Ice const &m)
{
	std::cout << "Ice assignment operator" << std::endl;
	if (this != &m)
		this->_type = m.getType();
	return (*this);
}

std::ostream& operator<<(std::ostream &stream, const Ice& m)
{
    stream << "Type: " << m.getType() << std::endl;
    return stream;
}
