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

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		this->_learnedMaterias[i] = NULL;
	}
	std::cout << "MateriaSource constructor" << std::endl;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (m._learnedMaterias[i])
			this->_learnedMaterias[i] = m._learnedMaterias[i]->clone();
	}
	std::cout << "MateriaSource copy constructor" << std::endl;
	return ;
}

MateriaSource::~MateriaSource(void)
{
	for (size_t i = 0; i < 4; i++)
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
	if (this != &m)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (this->_learnedMaterias[i])
			{
				delete this->_learnedMaterias[i];
				this->_learnedMaterias[i] = NULL;
			}
			if (m._learnedMaterias[i])
				this->_learnedMaterias[i] =  m._learnedMaterias[i]->clone();			
		}
	}
	std::cout << "MateriaSource assignment operator" << std::endl;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (size_t i = 0; i < 4; ++i)
	{
		if (!_learnedMaterias[i])
		{
			_learnedMaterias[i] = m;
			std::cout << "Learned Materia of type " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << "Can't learn more than 4 Materia" << std::endl;
}


AMateria*	MateriaSource::createMateria(std::string const &type)
{
	int i;

	i = 0;
	while (i < 4 && _learnedMaterias[i])
	{
		if (_learnedMaterias[i]->getType() == type)
		{
			std::cout << "Created Materia of type " << _learnedMaterias[i]->getType() << std::endl;
			return (this->_learnedMaterias[i]->clone());
		}
		i++;
	}
	std::cout << "Type " << type << " not found. Unable to create materia" << std::endl;
	return (0);
}
