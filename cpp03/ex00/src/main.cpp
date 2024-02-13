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

int	main(void)
{
	ClapTrap claptrap1("Clap1");
	ClapTrap claptrap2 = claptrap1; // Copy Constructor
	ClapTrap claptrap3("Clap2");
	claptrap3 = claptrap1; // Assignment Operator
	claptrap1.attack("Target1");
	claptrap1.takeDamage(5);
	claptrap1.beRepaired(3);
	return (0);
}
