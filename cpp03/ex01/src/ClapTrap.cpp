/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:32:47 by lucperei          #+#    #+#             */
/*   Updated: 2024/04/23 23:17:09 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
/*
Construtor padrão, ele é chamado sempre que um novo objeto ClapTrap é criado.
Inicializa os membros _name, _hitPoints, _energyPoints e _attackDamage.
Imprime uma mensagem informando que o construtor padrão foi chamado.
*/
ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default Constructor called for ClapTrap " << name << "!" << std::endl;
}

/*
O construtor de cópia é chamado quando um novo objeto ClapTrap é criado a partir de outro objeto ClapTrap.
Inicializa os membros do novo objeto com os valores do objeto original.
Imprime uma mensagem informando que o construtor de cópia foi chamado.
*/
ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy Constructor called for ClapTrap " << other._name << "!" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

/*
Operador de atribuição, sobrecarrega o operador de atribuição 
para atribuir um objeto ClapTrap a outro.
Verifica se não é a mesma instância.
Copia os membros do objeto passado para o objeto atual.
Retorna uma referência para o objeto atual.
Imprime uma mensagem informando que o operador de atribuição foi chamado.
*/
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Assignment Operator called for ClapTrap " << other._name << "!" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

/*
O destrutor é chamado quando um objeto ClapTrap é destruído.
Libera qualquer recurso alocado dinamicamente, se houver.
Imprime uma mensagem informando que o destrutor foi chamado.
*/
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for ClapTrap " << this->_name << "!" << std::endl;
}

/*
Método attack que verifica se o robô tem pontos de vida 
e energia suficientes para atacar.
Se sim, imprime uma mensagem informando o ataque e decrementa os pontos de energia.
Se não, imprime uma mensagem informando que o robô não pode atacar.
*/
void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
				<< this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	} else {
		std::cout << "ClapTrap " << this->_name << " can't attack. No hit points or energy left!" << std::endl;
	}
}

/*
Método takeDamage, reduz os pontos de vida do robô com 
base na quantidade de dano recebido.
Imprime uma mensagem informando o dano recebido e os pontos de vida restantes.
*/
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0) {
		this->_hitPoints -=  amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage. "
				<< "Remaining hit points: " << this->_hitPoints << std::endl;
	} else {
		std::cout << "ClapTrap " << this->_name << " can't take more damage. No hit points left!" << std::endl;
	}
}

/*
Método beRepaired, 
Incrementa os pontos de vida do robô com base na quantidade de reparo.
Decrementa os pontos de energia.
Imprime uma mensagem informando a quantidade de pontos de vida recuperados e o total de pontos de vida.
*/
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points. "
					<< "Total hit points: " << this->_hitPoints << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	} else {
		std::cout << "ClapTrap " << this->_name << " can't be repaired. No hit points left!" << std::endl;
	}
}

/*
Métodos getHitPoints(), getEnergyPoints(), getAttackDamage():
São métodos de acesso que retornam os valores dos membros correspondentes
*/
int ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

int ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

/*
Operador << (stream de saída):
Sobrecarrega o operador de inserção para imprimir as estatísticas do robô 
(pontos de vida, pontos de energia e dano de ataque).
*/
std::ostream& operator<<(std::ostream& os, const ClapTrap& claptrap)
{
	os << "stats:" << std::endl;
	os << "Hit Points: " << claptrap.getHitPoints() << std::endl;
	os << "Energy Points: " << claptrap.getEnergyPoints() << std::endl;
	os << "Attack Damage: " << claptrap.getAttackDamage() << std::endl;
	return (os);
}
