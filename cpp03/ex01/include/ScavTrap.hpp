/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:52:26 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 17:56:16 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap(void);
	ScavTrap& operator=(const ScavTrap& other);
	void guardGate(void);
};

#endif
