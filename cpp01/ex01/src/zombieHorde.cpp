#include "../include/Zombie.hpp"

/*
Parâmetros da Função:
N: Representa o número de zombies.
name: Representa o nome dos zombies.
*/
Zombie*	zombieHorde(int N, std::string name)
{
	// Declara um ponteiro
	Zombie* zombieArray;
	// Aloca dinamicamente memória para um array de N objetos Zombie. 
	// Cada objeto é inicializado com o construtor padrão.
	zombieArray = new Zombie[N]; 
	for (int i = 0; i < N; ++i) // Itera sobre o array de zombies.
	{
		// Para cada elemento do array, cria um novo objeto Zombie com o nome fornecido 
		// e o armazena no array.
		zombieArray[i] = Zombie(name);
	}
	return (zombieArray); // Retorna o ponteiro para o array de zombies criado dinamicamente.
}
