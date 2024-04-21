/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 08:21:29 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 08:25:03 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
/*
De forma geral, este programa cria objetos ClapTrap, realiza operações de cópia e atribuição entre eles, 
e em seguida, chama algumas funções membro para simular ações de ataque, dano e reparo em um desses objetos.
*/
int	main(void)
{
	std::cout << "\n ---------- Start Of Teste | ClapTrap ---------- \n" << std::endl;
	std::cout << "Create ClapTrap object using default constructor:\n";
	ClapTrap ana("Ana");
	std::cout << "Create Ana and initialize variables with " << ana << std::endl;
	ClapTrap jane("Jane");
	std::cout << "Create Jane and initialize variables with " << jane << std::endl;
	
	std::cout << "Copy constructor to create a new ClapTrap object called copy_ana\n";
	ClapTrap copy_ana = ana;
	std::cout << std::endl;

	std::cout << "Used the assignment operator to copy attributes from ClapTrap Ana:\n";
	copy_ana = ana;

	std::cout << "\n ---------- Start Of Feature Testing ---------- \n" << std::endl;

	std::cout << "Step 1 | Start of Ana's attack simulation on Jane:\n" << std::endl;

	ana.attack("Jane");
	jane.takeDamage(1);
	std::cout << "Ana´s " << ana << std::endl;
	std::cout << "Jane´s " << jane << std::endl;

	std::cout << "Step 2 | Jane repairs from the attack and restores hit points:\n" << std::endl;
	jane.beRepaired(1);
	jane.attack("Ana");
	ana.takeDamage(1);
	std::cout << "Jane´s " << jane << std::endl;
	std::cout << "Ana´s " << ana << std::endl;

	std::cout << " ------- End Testing With The Destructor ------ \n" << std::endl;

	return (0);
}
