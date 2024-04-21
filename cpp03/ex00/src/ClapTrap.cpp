/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:32:47 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 16:21:17 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

/*
Construtor é chamado quando um novo objeto ClapTrap é criado. Ele inicializa os 
membros _name, _hitPoints, _energyPoints e _attackDamage, e imprime uma mensagem 
indicando que um construtor foi chamado.
*/
ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor called for ClapTrap " << name << "!" << std::endl;
}

/*
Construtor de cópia que é chamado quando um novo objeto ClapTrap é criado a partir 
de outro objeto ClapTrap. Ele copia os valores dos membros do objeto passado como argumento 
para o novo objeto sendo criado e imprime uma mensagem indicando que um construtor de cópia 
foi chamado.
*/
ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy Constructor called for ClapTrap " << other._name << "!" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}

/*
O operador de atribuição ClapTrap& ClapTrap::operator=(const ClapTrap& other) é sobrecarregado para 
permitir a atribuição entre objetos ClapTrap. Ele copia os valores dos membros do objeto passado como 
argumento para o objeto que está sendo atribuído e imprime uma mensagem indicando que o operador de 
atribuição foi chamado.
*/
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

/*
O destrutor ClapTrap::~ClapTrap() é chamado quando um objeto ClapTrap é destruído. 
Ele libera quaisquer recursos que o objeto possa ter alocado e imprime uma mensagem indicando que o 
destrutor foi chamado.
*/
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for ClapTrap " << _name << "!" << std::endl;
}

/*
Funções membro:
-> void ClapTrap::attack(const std::string& target)
-> void ClapTrap::takeDamage(unsigned int amount)
-> void ClapTrap::beRepaired(unsigned int amount)
*/

/*
Na função membro attack ele esta verificando se ainda possui pontos de vida (_hitPoints) e 
pontos de energia (_energyPoints), pois não pode fazer nada sem não tiver um deles, ou os dois.
Atacar custa 1 _energyPoints(ponto de energia)
*/
void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0) {
		_attackDamage++; 
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
				<< (_attackDamage > 1 ? 1 : _attackDamage) << " points of damage!" << std::endl;
		_energyPoints--;
		_attackDamage--; 
	} else {
		std::cout << "ClapTrap " << _name << " can't attack. No hit points or energy left!" << std::endl;
	}
}

/*
A função membro de sofrer dano, verifica se ainda possui pontos de vida (_hitPoints) para simular o ClapTrap 
recebendo danos. Isso garante que o ClapTrap ainda está vivo e pode receber danos.
Se o ClapTrap tem pontos de vida restantes, o código prossegue para calcular os danos recebidos.
Ou seja, recebendo danos, calcula os pontos de vida restantes após os danos e imprime uma mensagem informando 
sobre os danos recebidos e os pontos de vida restantes.
*/
void	ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints > 0) {
	/*
	Se amount (o valor dos danos recebidos) for maior ou igual aos pontos de vida restantes 
	(_hitPoints), os pontos de vida são definidos como 0, indicando que o ClapTrap foi destruído.
	Caso contrário, subtrai-se amount dos pontos de vida restantes _hitPoints.
	*/	
        _hitPoints = (amount >= _hitPoints) ? 0 : _hitPoints - amount;
	_attackDamage = amount;
	/*
	Após calcular os danos recebidos, uma mensagem é impressa na saída padrão (std::cout) informando 
 	sobre os danos recebidos e os pontos de vida restantes do ClapTrap
	*/
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage. "
                  << "Remaining hit points: " << _hitPoints << std::endl;
    } else {
	/*
 	Se o ClapTrap não tem mais pontos de vida, ou seja, _hitPoints é 0, uma mensagem específica é 
  	impressa indicando que o ClapTrap não pode mais receber danos, pois já está destruído.
	*/
        std::cout << "ClapTrap " << _name << " can't take more damage. No hit points left!" << std::endl;
    }
}

/*
Quando ClapTrap se repara, ele recupera <amount>, _hitPoints (pontos de vida), porem se 
reparar custa 1 _energyPoints(ponto de energia).
Ela aumenta os pontos de vida do ClapTrap de acordo com a quantidade especificada e reduz 
seus pontos de energia.
*/
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

unsigned int ClapTrap::getHitPoints(void) const
{
    return (_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
    return (_energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void) const
{
    return (_attackDamage);
}

// Pega as propriedades atualizadas para passar para o status
std::ostream& operator<<(std::ostream& os, const ClapTrap& claptrap) {
    os << "stats:" << std::endl;
    os << "Hit Points: " << claptrap.getHitPoints() << std::endl;
    os << "Energy Points: " << claptrap.getEnergyPoints() << std::endl;
    os << "Attack Damage: " << claptrap.getAttackDamage() << std::endl;
    return os;
}
