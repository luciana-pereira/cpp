#include "../include/Zombie.hpp"

// A função chamada newZombie que cria dinamicamente um novo objeto da classe Zombie e 
// retorna um ponteiro para esse objeto. Resumindo, a função newZombie é responsável por 
// criar um novo objeto da classe Zombie com o nome especificado e retornar um ponteiro para esse objeto.

Zombie	*newZombie(std::string name)
{
	// Esta parte da função cria dinamicamente um novo objeto da classe Zombie, utilizando o 
	// operador new, e passa o parâmetro name para o construtor da classe Zombie. Em seguida, 
	// retorna o ponteiro para esse novo objeto criado.
	return (new Zombie(name));
}
