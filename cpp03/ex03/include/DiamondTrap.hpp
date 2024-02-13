/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:21:02 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 22:37:52 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string	_name;
public:
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& other);
	~DiamondTrap(void);
	DiamondTrap& operator=(const DiamondTrap& other);
	void	whoAmI(void);
};

#endif
