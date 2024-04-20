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
	// Cria um objeto ClapTrap chamado claptrap1 com o nome "Clap1".
	ClapTrap claptrap1("Clap1");
	
	/*
	Usa o construtor de cópia para criar um novo objeto ClapTrap chamado claptrap2, 
  	que é uma cópia do objeto claptrap1. Portanto, o construtor de cópia é chamado.
	*/
	ClapTrap claptrap2 = claptrap1;
	
	// Cria um novo objeto ClapTrap chamado claptrap3 com o nome "Clap2".
	ClapTrap claptrap3("Clap2");
	
	/*
	Usa o operador de atribuição para atribuir os valores do objeto 
 	claptrap1 ao objeto claptrap3. Portanto, o operador de atribuição é chamado.
	*/
	claptrap3 = claptrap1;

	// Chama a função attack no objeto claptrap1, simulando um ataque ao alvo "Target1".
	claptrap1.attack("Target1");
	// Chama a função takeDamage no objeto claptrap1, simulando o ClapTrap recebendo 5 pontos de dano.
	claptrap1.takeDamage(5);
	/*
	Chama a função beRepaired no objeto claptrap1, simulando a recuperação do ClapTrap com 3 pontos 
 	de reparo.
 	*/ 
	claptrap1.beRepaired(3);
	return (0);
}
