#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class	HumanA
{
private:
	std::string _name;
	Weapon _weapon;
public:
	HumanA(const std::string& humanName, const Weapon& initialWeapon);
	void	attack(void);
};

#endif
