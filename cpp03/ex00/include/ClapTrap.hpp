/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:02:44 by lucperei          #+#    #+#             */
/*   Updated: 2024/04/23 23:13:54 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class	ClapTrap
{
private:
	std::string		_name;
	int				_hitPoints;
	int				_energyPoints;
	int				_attackDamage;
public:
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap&	operator=(const ClapTrap& other);
	~ClapTrap();
	void		 attack(const std::string& target);
	void		 takeDamage(unsigned int amount);
	void		 beRepaired(unsigned int amount);
	int 		 getHitPoints(void) const;
	int 		 getEnergyPoints(void) const;
	int 		 getAttackDamage(void) const;
};

std::ostream &operator<<(std::ostream &ou, const ClapTrap& claptrap);

#endif
