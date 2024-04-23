/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:11:59 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 17:54:40 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
// classe ScavTrap, uma classe derivada de ClapTrap

#include "../include/ScavTrap.hpp"

/*
Construtor ScavTrap
Este é um construtor parametrizado para a classe ScavTrap.
Ele inicializa um objeto ScavTrap com o nome fornecido.
Chama explicitamente o construtor parametrizado da classe base ClapTrap com o nome fornecido.
Imprime uma mensagem informando que o construtor parametrizado foi chamado.
*/
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Parameterized Constructor called" << std::endl;
}

/*
Construtor de cópia
Este é um construtor de cópia para a classe ScavTrap.
Ele inicializa um novo objeto ScavTrap com base em outro objeto ScavTrap passado como parâmetro.
Chama explicitamente o construtor de cópia da classe base ClapTrap com o objeto passado.
Imprime uma mensagem informando que o construtor de cópia foi chamado.
*/
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

/*
Destrutor ~ScavTrap(void):
Este é o destrutor da classe ScavTrap.
É chamado quando um objeto ScavTrap é destruído.
Imprime uma mensagem informando que o destrutor foi chamado.
*/
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

/*
Operador de atribuição ScavTrap& operator=(const ScavTrap& other):
Sobrecarrega o operador de atribuição para atribuir um objeto ScavTrap a outro.
Verifica se não é a mesma instância.
Chama explicitamente o operador de atribuição da classe base ClapTrap com o objeto passado.
Retorna uma referência para o objeto atual.
Imprime uma mensagem informando que o operador de atribuição foi chamado.
*/
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap Assignment Operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

/*
Método guardGate():
Este é um método específico da classe ScavTrap.
Imprime uma mensagem informando que o ScavTrap está agora em modo de guarda.
*/
void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
