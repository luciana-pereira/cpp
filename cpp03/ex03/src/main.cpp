/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:20:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 22:27:38 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap diamondTrap("DiamondTrap");
	diamondTrap.attack("Enemy");
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.whoAmI();
	DiamondTrap anotherDiamondTrap = diamondTrap;
	anotherDiamondTrap.takeDamage(20);
	anotherDiamondTrap.beRepaired(10);
	anotherDiamondTrap.whoAmI();
    return (0);
}
