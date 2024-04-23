/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:47:04 by lucperei          #+#    #+#             */
/*   Updated: 2024/04/23 22:02:03 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

// Definição do Construtor Padrão
FragTrap::FragTrap(void)
	: ClapTrap() // Chama o construtor padrão de ClapTrap
{
	// Inicializa os membros de dados específicos de FragTrap
	this->_name = "FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

// Definição do Construtor de Inicialização
FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name) // Chama o construtor de inicialização de ClapTrap
{
    // Inicializa os membros de dados específicos de FragTrap
    std::cout << "FragTrap Constructor called for " << name << "!" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

// Definição do Construtor de Cópia 
FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other) // Chama o construtor de cópia de ClapTrap
{
	std::cout << "FragTrap Copy Constructor called for " << other._name << "!" << std::endl;
	*this = other;
}

// Definição do Destrutor
FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called for FragTrap " << this->_name << "!" << std::endl;
}

// Definição do Operador de Atribuição
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap Assignment Operator called for " << other._name << "!" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing "
				<<  this->_attackDamage << " points of damage!" << std::endl;
		 this->_energyPoints--;
	} else {
		std::cout << "FragTrap " <<  this->_name << " can't attack. No hit points or energy left!" << std::endl;
	}
}

// Esta função so exibe uma solicitação de comprimento.
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " requests a positive high five!" << std::endl;
}
