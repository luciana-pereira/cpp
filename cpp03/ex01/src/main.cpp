/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:12:04 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 17:58:39 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int	main(void)
{
	std::cout << "Test 1:" << std::endl;
	ScavTrap scavTrap1("Scav1");
	scavTrap1.attack("Enemy");
	std::cout << std::endl << "Test 2:" << std::endl;
	ScavTrap scavTrap2("Scav2");
	scavTrap2.takeDamage(30);
	scavTrap2.beRepaired(10);
	std::cout << std::endl << "Test 3:" << std::endl;
	scavTrap1.guardGate();
	return (0);
}
