#include "../include/Zombie.hpp"

int	main(void)
{
	Zombie	*zombieArray;

	zombieArray = zombieHorde(5, "BrainEater");
	for (int i = 0; i < 5; ++i)
	{
		zombieArray[i].announce();
	}
	delete[] zombieArray;
	return (0);
}
