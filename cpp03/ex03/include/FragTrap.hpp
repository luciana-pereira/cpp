/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:52:05 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 22:42:49 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "../include/ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
public:
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	~FragTrap();
	FragTrap& operator=(const FragTrap& other);
	void highFivesGuys(void);
};

#endif
