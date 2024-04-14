#include "../include/Zombie.hpp"

// Construtor, que so inicializa um objeto Zombie.
Zombie::Zombie(void) {}

// Construtor da classe Zombie, ele inicializa o atributo _name com o valor passado como argumento. 
// Isso permite criar um objeto Zombie com um nome específico.
Zombie::Zombie(std::string name) : _name(name) {}

// Destrutor da classe Zombie, chamado quando um objeto Zombie é destruído. 
// Ele imprime uma mensagem indicando que o zombie foi destruído, juntamente com seu nome.
Zombie::~Zombie(void)
{
	std::cout << _name << " has been destroyed" << std::endl;
}

// Método imprime uma mensagem indicando que o zombie está anunciando, junto com seu nome.
void Zombie::announce(void)
{
	std::cout << _name << " says: Braiiiiiiinnnssss..." << std::endl;
}
