/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:38:06 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/14 14:07:40 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

class	Character : public ICharacter
{
private:
	std::string _name;
	AMateria* _inventory[4];
public:
	Character(void);
	Character(std::string const &name);
	~Character(void); 
	Character(Character const &m);
	Character& operator=(Character const &m);
	std::string const &getName() const;
	AMateria*	getMateria(int idx);
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
