#include "../include/HumanB.hpp"

/* 
O objeto está sendo inicializado apenas com um nome (name). Não há arma inicial fornecida.
De forma geral o construtor utiliza uma inicialização de membro (member initializer list) para 
inicializar os membros name e weapon.

O membro name (do tipo std::string) é inicializado com o valor passado como argumento name.
O membro weapon (um ponteiro para Weapon) é inicializado com NULL, indicando que o humano 
está desarmado.
*/
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

/*
Neste método setWeapon(Weapon& weapon), é recebida uma nova arma como parâmetro. 
Este método é usado para definir a arma do humano. Este novo objeto é atribuído ao ponteiro weapon.
*/
void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

/*
No método attack(), é verificado se o ponteiro weapon não é nulo:
Se não for nulo, significa que o humano está armado. Então, uma mensagem é exibida indicando que o humano 
está atacando com sua arma, incluindo o tipo da arma.
Se for nulo, significa que o humano está desarmado. Nesse caso, uma mensagem é exibida indicando que o 
humano está desarmado.

Ou seja, o método attack() é responsável por exibir a mensagem formatada com o nome do humano e, se 
estiver armado, o tipo de arma com que está atacando. Se estiver desarmado, uma mensagem informando 
isso é exibida. 
*/
void	HumanB::attack(void)
{
	if (weapon != NULL)
	{
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	} 
	else
	{
		std::cout << _name << " is unarmed" << std::endl;
	}
}
