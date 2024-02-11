#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

class Zombie
{
private:
	std::string _name;

public:
	Zombie(std::string name);
	~Zombie(void);
	void	announce(void);
};

Zombie*	newZombie(std::string _name);
void	randomChump(std::string _name);

#endif
