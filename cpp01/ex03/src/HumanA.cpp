#include "../include/HumanA.hpp"

// No construtor de HumanA, o objeto está sendo inicializado com um nome (humanName) 
// e uma arma inicial (initialWeapon). Ele uma inicialização de membro (member initializer list) 
// para inicializar os membros _name e _weapon.
HumanA::HumanA(const std::string& humanName, const Weapon& initialWeapon)
	: _name(humanName), _weapon(initialWeapon) {}

// Este método exibira uma mensagem indicando que o humano está atacando com sua arma.
// Ela exibira o nome do humano e a função getType() é chamada no objeto Weapon armazenado 
// em _weapon para obter o tipo da arma.
// Este o método é responsável por exibir a mensagem formatada com o nome do humano e o tipo 
// de arma com que está atacando.
void HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << weapon.getType() << std::endl;
}
