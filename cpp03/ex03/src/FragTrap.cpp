/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:47:04 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 20:51:17 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{
    std::cout << "FragTrap Constructor called for " << name << "!" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other)
{
	std::cout << "FragTrap Copy Constructor called for " << other._name << "!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called for " << _name << "!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap Assignment Operator called for " << other._name << "!" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
}
