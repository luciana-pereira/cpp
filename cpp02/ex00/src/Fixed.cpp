/*
Aqui implementamos a classe Fixed que representa um número fixo de ponto flutuante.
Essencialmente, esta classe registra mensagens de saída para diferentes eventos, como construção, destruição, cópia e atribuição de objetos. 
Isso é útil para entender o fluxo de execução e depurar problemas relacionados à construção e destruição de objetos Fixed.
*/

#include "../include/Fixed.hpp"

/*
Construtor padrão da classe Fixed que inicializa fixedValue  como 0 e 
imprime uma mensagem indicando que o construtor padrão foi chamado.
*/
Fixed::Fixed(void) : fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*
Construtor de cópia da classe Fixed que imprime uma mensagem indicando que o construtor de cópia foi chamado.
Chama o operador de atribuição para copiar o valor de other para o objeto atual.
*/
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/*
Destrutor da classe Fixed que imprime uma mensagem indicando que o destrutor foi chamado.
*/
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// Abaixo temos os dois métodos de acesso getRawBits e setRawBits

/*
O método getRawBits, retorna o valor de fixedValue e 
imprime uma mensagem indicando que o método getRawBits foi chamado.
*/
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedValue);
}

/*
O método setRawBits, define o valor de fixedValue como raw e 
imprime uma mensagem indicando que o método setRawBits foi chamado.
*/
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixedValue = raw;
}

/*
Operador de atribuição, imprime uma mensagem indicando que o operador de atribuição foi chamado.
Verifica se o objeto atual(this) não é o mesmo que other. Se eles forem diferentes, 
copia o valor de other para o objeto atual.
*/
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		fixedValue = other.getRawBits();
	}
	return (*this);
}
