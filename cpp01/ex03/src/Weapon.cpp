#include "Weapon.hpp"

/*
Defini uma classe Weapon que representa uma arma com um tipo associado. Ele permite a inicialização 
da arma com um tipo específico, a recuperação desse tipo e a modificação do tipo posteriormente.
*/

/*
No construtor uma arma é inicializada com um tipo fornecido como parâmetro. 
Isso é feito através da inicialização do membro type com o valor passado.
*/
Weapon::Weapon(const std::string& initialType) : type(initialType) {}

const std::string& Weapon::getType(void)
{
	return (type);
}

void Weapon::setType(const std::string& newType)
{
	type = newType;
}
