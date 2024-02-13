/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:18:28 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 21:02:32 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int	main(void)
{
	ClapTrap claptrap("Clappy");
	claptrap.attack("Target");
	claptrap.takeDamage(20);
	claptrap.beRepaired(10);

	ScavTrap scavtrap("Scavy");
	scavtrap.attack("Target");
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(15);
	scavtrap.guardGate();

	FragTrap fragtrap("Fraggy");
	fragtrap.attack("Target");
	fragtrap.takeDamage(40);
	fragtrap.beRepaired(20);
	fragtrap.highFivesGuys();

	return (0);
}
