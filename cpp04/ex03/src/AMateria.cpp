/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:45:16 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/14 06:32:04 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"

AMateria::AMateria(void): _type("")
{
	std::cout << "Abstract Materia constructor" << std::endl;
	return ;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "Abstract Materia constructor" << std::endl;
	return ;
}

AMateria::AMateria(AMateria const &m)
{
	std::cout << "Abstract Materia copy constructor" << std::endl;
	*this = m;
	return ;
}


AMateria::~AMateria(void)
{
	std::cout << "Abstract Materia destructor" << std::endl;
	return ;
}

std::string const &AMateria::getType(void) const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
}

AMateria& AMateria::operator=(AMateria const &m)
{
	std::cout << "Abstract Materia assignment operator" << std::endl;
	if (this != &m)
		this->_type = m.getType();
	return (*this);
}
