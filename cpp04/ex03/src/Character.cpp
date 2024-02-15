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
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	std::cout << "Character default constructor" << std::endl;
	return ;
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	std::cout << "Character constructor" << std::endl;
	return ;
}

Character::Character(const Character &m)
{
    _name = m._name;
    for (size_t i = 0; i < 4; i++)
    {
        if (m._inventory[i])
            _inventory[i] = m._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    std::cout << "Character copy constructor" << std::endl;
	return ;
}


Character::~Character(void)
{
	for (size_t i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
	std::cout << "Character " << this->_name << " destructor" << std::endl;
	return ;
}


std::string const &Character::getName() const
{
	return (this->_name);
}

AMateria* Character::getMateria(int idx)
{
	return (this->_inventory)[idx];
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << _name << " tried to equip nothing..." << std::endl;
		return ;
	}
	int	index;
	for (index = 0; index < 4 && _inventory[index]; ++index);
	if (index < 4)
	{
		_inventory[index] = m;
		std::cout << _name << " equipped materia " << _inventory[index]->getType()
			<< " in slot " << index << std::endl;
	}
	else
		std::cout << _name << " can't equip more than " << 4 << " Materia" << std::endl;
}


void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		std::cout << _name << " tried to unequip nothing in slot " << idx << std::endl;
	else if (!_inventory[idx])
		std::cout << _name << " has nothing equipped in slot " << idx << " to unequip" << std::endl;
	else
		std::cout << _name << " unequip in slot " << idx << std::endl, _inventory[idx] = NULL;
}


void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		std::cout << _name << " tried to use nothing in slot " << idx << std::endl;
	else if (!_inventory[idx])
		std::cout << _name << " has nothing equipped in slot " << idx << " to use" << std::endl;
	else
		_inventory[idx]->use(target);
}

Character& Character::operator=(Character const &m)
{
	if (this == &m)
		return (*this);

	this->_name = m._name;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		if (m._inventory[i])
		{
			this->_inventory[i] = m._inventory[i]->clone();
		}
	}
	std::cout << "Character assignment operator" << std::endl;
	return (*this);
}


