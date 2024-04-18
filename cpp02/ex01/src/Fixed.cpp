/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:24:28 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 02:45:21 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

/*
Construtor padrão Fixed::Fixed(), que inicializa _value para 0 e 
imprime uma mensagem indicando que o construtor padrão foi chamado.
*/
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*
Construtor de cópia Fixed::Fixed(const Fixed& other), que imprime uma mensagem indicando 
que o construtor de cópia foi chamado e copia os dados do objeto other para o objeto atual 
usando o operador de atribuição.
*/
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/*
5) Esse construtor recebe um valor inteiro como parâmetro e o converte para um valor fixo. 
Ele faz isso deslocando o valor inteiro para a esquerda pelo número de bits fracionários e armazenando 
o resultado no membro de dados _value. Isso cria uma instância da classe Fixed com o valor especificado 
como parte inteira e zero como parte fracionária.
*/
Fixed::Fixed(const int value) : _value(value << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

/*
O operador de atribuição Fixed& Fixed::operator=(const Fixed& other), que imprime uma mensagem indicando que o operador de
atribuição foi chamado e atribui o valor _value do objeto other para o objeto atual.
*/
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_value = other._value;
	}
	return (*this);
}

/*
1) Neste construtor e possivel aceitar um valor de ponto flutuante como parametro, ele converte
um valor de ponto flutuante em um valor de ponto fixo.
Multiplica o valor de ponto flutuante por 1 << _fractionalBits, o que é equivalente a deslocar 1 
para a esquerda _fractionalBits vezes. 
Isso é feito para converter o valor de ponto flutuante em um valor inteiro correspondente ao valor de ponto fixo.
Em seguida, o valor resultante é arredondado usando a função roundf() da biblioteca <cmath>.
O valor arredondado é atribuído à variável membro _value.
*/
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (float)(1 << _fractionalBits));
}

/*
Destructor, que imprime uma mensagem indicando que o destrutor foi chamado.
*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*
4) Esta função membro retorna o valor do objeto Fixed convertido para um ponto flutuante. Ela faz isso dividindo o valor bruto 
armazenado no objeto Fixed pelo valor de 2 elevado ao número de bits fracionários, representado por _fractionalBits. Isso 
resulta na representação correta do valor de ponto fixo em um valor de ponto flutuante.
*/
float	Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (float)(1 << _fractionalBits));
}

/*
3) Esta função membro retorna o valor do objeto Fixed convertido para um inteiro, onde os bits fracionários são descartados. 
Ele faz isso deslocando para a direita o valor bruto armazenado no objeto Fixed pelo número de bits fracionários, representado por _fractionalBits.
*/
int	Fixed::toInt(void) const
{
	return (getRawBits() >> _fractionalBits);
}

/*
Função membro int Fixed::getRawBits(void) const, que retorna o valor de ponto fixo armazenado em _value.
*/
int	Fixed::getRawBits(void) const
{
	return (_value);
}

/*
A função membro setRawBits atribui um novo valor direto ao membro _value da classe Fixed
*/
void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}


/*
2) Esta função sobrecarrega o operador de inserção (<<) para que seja capaz de imprimir objetos da classe Fixed em fluxos de saída, 
como std::cout. Quando você tenta imprimir um objeto Fixed usando std::cout, esta função é chamada, convertendo o valor do objeto 
Fixed para um valor de ponto flutuante usando a função toFloat(), e então imprimindo esse valor no fluxo de saída fornecido.

std::ostream, que representa o fluxo de saída onde os dados serão inseridos.
*/
std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
