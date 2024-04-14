#include "../include/HumanA.hpp"

// No construtor de HumanA, o objeto está sendo inicializado com um nome (name) 
// e uma arma inicial (weapon). Ele uma inicialização de membro (member initializer list) 
// para inicializar os membros _name e _weapon.
HumanA::HumanA(std::string name, Weapon& weapon)
	: _name(name), _weapon(weapon) {}

// Este método exibira uma mensagem indicando que o humano está atacando com sua arma.
// Ela exibira o nome do humano e a função getType() é chamada no objeto Weapon armazenado 
// em _weapon para obter o tipo da arma.
// Este o método é responsável por exibir a mensagem formatada com o nome do humano e o tipo 
// de arma com que está atacando.
void HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
