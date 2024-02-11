#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class	Weapon
{
private:
	std::string _type;
public:
	Weapon(const std::string& initialType);
	const std::string&	getType(void);
	void	setType(const std::string& newType);
};

#endif
