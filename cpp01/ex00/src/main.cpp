#include "../include/Zombie.hpp"

int	main()
{
	Zombie*	zombie1;

	randomChump("Bar");
	zombie1 = newZombie("Foo");
	zombie1->announce();
	delete zombie1;
	return (0);
}
