#include "../include/HumanA.hpp"

HumanA::HumanA(const std::string& humanName, const Weapon& initialWeapon)
	: _name(humanName), _weapon(initialWeapon) {}

void HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << weapon.getType() << std::endl;
}
