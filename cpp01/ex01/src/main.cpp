#include "../include/Zombie.hpp"

int	main(void)
{
	// Declara um ponteiro para objetos Zombie
	Zombie	*zombieArray;

	// Chama a função zombieHorde para criar um exército de 5 zombies com o nome "BrainEater". 
	// O ponteiro retornado pela função zombieHorde é armazenado na variável zombieArray.
	zombieArray = zombieHorde(5, "BrainEater");
	for (int i = 0; i < 5; ++i) // Itera sobre o array de zombies.
	{
		// Para cada zombie no array, chama o método announce para anunciar o zombie.
		zombieArray[i].announce();
	}
	// Libera a memória alocada dinamicamente para o array de zombies, garantindo que não 
	// haja vazamento de memória.
	delete[] zombieArray;
	return (0);
}
