#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>


class HumanB
{
private:
	std::string	_name;
	Weapon*	_weapon;

public:
	HumanB(const std::string& humanName);
	~HumanB(void);
	void	setWeapon(const Weapon& newWeapon);
	void	attack(void);
};

#endif
