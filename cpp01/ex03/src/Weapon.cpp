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

/*
A função e responsável por retornar o tipo da arma. Ela retorna uma referência constante para o membro type, 
garantindo que o tipo não possa ser modificado através do retorno desta função.
*/
const std::string& Weapon::getType(void)
{
	return (type);
}

/*
A função permite alterar o tipo da arma. Ela recebe um novo tipo como parâmetro e o atribui ao membro type. 
Essa função permite a modificação do tipo da arma após a sua criação.
*/
void Weapon::setType(const std::string& newType)
{
	type = newType;
}
