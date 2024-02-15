/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:40:01 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/15 01:13:37 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor" << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type)
{
	std::cout << "Cure constructor" << std::endl;
}

Cure::Cure(const Cure &m) : AMateria(m)
{
	std::cout << "Cure copy constructor" << std::endl;
	*this = m;
}

Cure::~Cure()
{
	std::cout << "Cure destructor" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure& Cure::operator=(const Cure &m)
{
	std::cout << "Cure assignment operator" << std::endl;
	if (this != &m)
		this->_type = m.getType();
	return (*this);
}

std::ostream& operator<<(std::ostream &stream, const Cure &m)
{
	stream << "Type: " << m.getType() << std::endl;
	return (stream);
}


