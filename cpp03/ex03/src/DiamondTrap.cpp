/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:25:28 by lucperei          #+#    #+#             */
/*   Updated: 2024/04/23 22:18:08 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"
#include "../include/ClapTrap.hpp"

//Definição do Construtor Padrão
DiamondTrap::DiamondTrap(void): ClapTrap("default_clap_name"), _name("default")
{
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
	FragTrap::_hitPoints = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_attackDamage = 30;
}

// Definição do Construtor de Inicialização
DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "DiamondTrap Constructor called for " << this->_name << "!" << std::endl;
	FragTrap::_hitPoints = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_attackDamage = 30;
}

// Definição do Construtor de Cópia
DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap Copy Constructor called for " << this->_name << "!" << std::endl;
	*this = other;
}

// Definição do Destrutor
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called for " << this->_name << "!" << std::endl;
}

// Definição do Operador de Atribuição
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap Assignment Operator called for " << other._name << "!" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		this->_name = other._name;
	}
	return (*this);
}
// A classe DiamondTrap está chamando a função attack da classe ScavTrap. Isso é possível porque DiamondTrap herda as funções públicas de ScavTrap devido à herança.
void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

// função membro chamada whoAmI(), que exibirá tanto o nome do DiamondTrap quanto o nome do ClapTrap.
void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
