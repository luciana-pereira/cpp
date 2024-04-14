#include "../include/Zombie.hpp"

// A função chamada randomChump que cria um objeto Zombie localmente na pilha de execução, 
// inicializado com o nome fornecido como parâmetro, e então chama o método announce() 
// desse objeto para que o zombie anuncie sua presença.


void	randomChump(std::string name)
{
	// Aqui, um objeto da classe Zombie chamado zombie é criado na pilha de execução, 
	// utilizando o construtor da classe Zombie que recebe um nome como parâmetro. 
	// Este objeto é criado localmente.
	Zombie zombie(name);
	// O método announce() do objeto zombie é chamado, fazendo com que o zombie 
	// anuncie sua presença imprimindo uma mensagem na saída padrão.
	zombie.announce();
}
