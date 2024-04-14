#include "../include/HumanB.hpp"

/* 
O objeto está sendo inicializado apenas com um nome (humanName). Não há arma inicial fornecida.
De forma geral o construtor utiliza uma inicialização de membro (member initializer list) para 
inicializar os membros name e weapon.

O membro name (do tipo std::string) é inicializado com o valor passado como argumento humanName.
O membro weapon (um ponteiro para Weapon) é inicializado com NULL, indicando que o humano está desarmado.
*/
HumanB::HumanB(const std::string& humanName) : name(humanName), weapon(NULL) {}

/*
No destrutor de HumanB, é verifico se o ponteiro para weapon não é nulo 
(ou seja, se aponta para algum objeto Weapon alocado dinamicamente). 
Se não for nulo, o objeto Weapon é deletado da memória para evitar vazamentos de memória.
*/
HumanB::~HumanB(void)
{
	delete weapon;
}

/*
Neste método setWeapon(const Weapon& newWeapon), é recebida uma nova arma como parâmetro. 
Este método é usado para definir a arma do humano. Se o ponteiro weapon já apontar para uma arma 
(ou seja, se não for NULL, isso e realizado no construtor), a arma anterior é deletada da memória 
para evitar vazamentos.
Em seguida, um novo objeto Weapon é criado no heap, usando o tipo da nova arma como argumento 
para o construtor. Este novo objeto é atribuído ao ponteiro weapon.
*/
void	HumanB::setWeapon(const Weapon& newWeapon)
{
	if (weapon != NULL)
	{
		delete weapon;
	}
	weapon = new Weapon(newWeapon.getType());
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
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	} 
	else
	{
		std::cout << name << " is unarmed" << std::endl;
	}
}
