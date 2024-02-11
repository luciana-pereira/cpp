#include "../include/HumanB.hpp"

HumanB::HumanB(const std::string& humanName) : name(humanName), weapon(nullptr) {}

HumanB::~HumanB(void)
{
	delete weapon;
}

void	HumanB::setWeapon(const Weapon& newWeapon)
{
	if (weapon != nullptr)
	{
		delete weapon;
	}
	weapon = new Weapon(newWeapon.getType());
}

void	HumanB::attack(void)
{
	if (weapon != nullptr)
	{
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	} 
	else
	{
		std::cout << name << " is unarmed" << std::endl;
	}
}
