/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:36:19 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/15 01:09:41 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

Character::Character(void) : _name("")
{
	for (int i = 0; i < 4; ++i)
	{
		_inventory[i] = NULL;
	}
	std::cout << "Character default constructor" << std::endl;
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
	{
		_inventory[i] = NULL;
	}
	std::cout << "Character constructor" << std::endl;
}

Character::Character(Character const &m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (m._inventory[i])
			_inventory[i] = m._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	std::cout << "Character copy constructor" << std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	std::cout << "Character " << _name << " destructor" << std::endl;
}

std::string const &Character::getName(void) const
{
	return (_name);
}

AMateria* Character::getMateria(int idx)
{
	return (_inventory[idx]);
}

void	Character::equip(AMateria* m)
{
	int	index;
	for (int i = 0; i < 4; ++i)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m->clone();
			std::cout << _name << " equipped materia of type " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << _name << " inventory full. Cannot equip Materia " << std::endl;
	if (!m)
		std::cout << _name << " tried to equip nothing..." << std::endl;
	index = 0;
	while (index < 4 && _inventory[index])
		index++;
	if (index < 4)
	{
		_inventory[index] = m;
		std::cout << _name << " equipped materia of type " << m->getType() << " in slots " << index << std::endl;
	}
	else
		std::cout << _name << " can´t equip more than " << 4 << " materia " << std::endl;
}

void	Character::unequip(int idx)
{
	if (_inventory[idx])
	{
		delete _inventory[idx];
		_inventory[idx] = NULL;
		std::cout << "Character " << _name << " unequipped" << std::endl;
	}
	else if (idx >= 0 && idx < 4)
	{
		std::cout << _name << " unequip in slot " << idx << std::endl;
		_inventory[idx] = NULL;
	}
	else if (idx >= 4 || idx < 0)
	{	
		std::cout << _name << " attempt to unequip in slot " << idx << std::endl;
	}
	else if (!_inventory[idx])
	{	
		std::cout << _name << " has nothing equipped in slot " << idx << " to unequip" << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
	{
		_inventory[idx]->use(target);
	}
	else if (idx >= 4 || idx < 0)
	{	
		std::cout << _name << " attempt to use in slot " << idx << std::endl;
	}
	else if (!_inventory[idx])
	{	
		std::cout << _name << " has nothing equipped in slot " << idx << " to use" << std::endl;
	}
}

Character& Character::operator=(Character const &m)
{
	for (size_t i = 0; i  < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		if (m._inventory[i])
			this->_inventory[i] = m._inventory[i]->clone();
	}
	std::cout << _name << "Character assignment operator" << std::endl;
	return (*this);
}
