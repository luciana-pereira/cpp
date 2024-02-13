/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:32:47 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 18:51:16 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "Constructor called for ClapTrap " << name << "!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy Constructor called for ClapTrap " << other._name << "!" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Assignment Operator called for ClapTrap " << other._name << "!" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for ClapTrap " << _name << "!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
				<< _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else {
		std::cout << "ClapTrap " << _name << " can't attack. No hit points or energy left!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints > 0) {
        _hitPoints = (amount >= _hitPoints) ? 0 : _hitPoints - amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage. "
                  << "Remaining hit points: " << _hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " can't take more damage. No hit points left!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints > 0) {
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points. "
                  << "Total hit points: " << _hitPoints << std::endl;
        _energyPoints--;
    } else {
        std::cout << "ClapTrap " << _name << " can't be repaired. No hit points left!" << std::endl;
    }
}
