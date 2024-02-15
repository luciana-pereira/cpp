/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:30:46 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/15 01:21:53 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _learnedCount(0)
{
	for (int i = 0; i < 4; ++i)
	{
		_learnedMaterias[i] = NULL;
	}
	std::cout << "MateriaSource constructor" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (m._learnedMaterias[i])
		{
			_learnedMaterias[i] = m._learnedMaterias[i]->clone();
			return ;
		}
	}
	std::cout << "MateriaSource copy constructor" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_learnedMaterias[i])
		{
			delete _learnedMaterias[i];
			_learnedMaterias[i] = NULL;
		}			
	}
	std::cout << "MateriaSource destructor" << std::endl;
}

MateriaSource& MateriaSource::operator=(MateriaSource const &m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_learnedMaterias[i])
		{
			delete _learnedMaterias[i];
			_learnedMaterias[i] = NULL;
		}
		if (m._learnedMaterias[i])
			_learnedMaterias[i] =  m._learnedMaterias[i]->clone();			
	}
	std::cout << "MateriaSource assignment operator" << std::endl;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (_learnedCount < 4)
	{
		_learnedMaterias[_learnedCount++] = m->clone();
		std::cout << "Learned Materia of type " << m->getType() << std::endl;
	}
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_learnedMaterias[i] && _learnedMaterias[i]->getType() == type)
		{
			std::cout << "Created Materia of type " << type << std::endl;
			return (_learnedMaterias[i]->clone());
		}
	}
	std::cout << "Type " << type << " not found. Unable to create Materia" << std::endl;
	return (NULL);
}
