#include "../include/Zombie.hpp"

// De forma geral está implementação dos métodos da classe Zombie, incluindo o construtor, o destruidor 
// e o método announce, que são responsáveis por criar, destruir e anunciar um zumbi, respectivamente.

// Define o construtor da classe Zombie. O construtor recebe um parâmetro name do tipo std::string e 
// inicializa o atributo _name com o valor fornecido. 
Zombie::Zombie(std::string name) : _name(name) {}

//  Define o destruidor da classe Zombie. No corpo do destruidor, imprime uma mensagem indicando que o 
// zumbi foi destruído, mostrando o nome do zumbi _name, conforme subject.
Zombie::~Zombie(void)
{
	std::cout << "Zombie " << _name << " has been destroyed!" << std::endl;
}

// Define o método announce() da classe Zombie, que não recebe parâmetros e não retorna valor so imprime a mensagem.
void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
