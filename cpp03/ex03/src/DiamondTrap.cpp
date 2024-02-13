/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:25:28 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 22:52:33 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"
#include "../include/ClapTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "DiamondTrap Constructor called for " << _name << "!" << std::endl;
	FragTrap::_hitPoints = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap Copy Constructor called for " << _name << "!" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called for " << this->_name << "!" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap Assignment Operator called for " << other._name << "!" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
