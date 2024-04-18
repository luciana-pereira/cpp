/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 07:08:08 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 07:33:29 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Método getRawBits: Retorna o valor armazenado no objeto Fixed.

Método setRawBits: Define o valor armazenado no objeto Fixed.

Método toFloat: Converte o valor armazenado no objeto Fixed para um ponto flutuante.

Método toInt: Converte o valor armazenado no objeto Fixed para um inteiro.

Sobrecarga do Operador de Saída (std::ostream& operator<<(std::ostream& out, const Fixed& fixed)): Permite a saída de um objeto Fixed para um fluxo de saída (como std::cout), convertendo o valor para ponto flutuante.

Esse código implementa uma classe Fixed que representa um número de ponto fixo e sobrecarrega diversos operadores para permitir operações matemáticas e comparações entre objetos Fixed.
*/
#include "../include/Fixed.hpp"
 /*
 Construtor Padrão (Fixed::Fixed(void)): Inicializa um objeto Fixed com o valor _value igual a 0.
 */
Fixed::Fixed(void) : _value(0) {}

/*
Construtor de Cópia (Fixed::Fixed(const Fixed &rhs)): Cria um novo objeto Fixed a partir de outro objeto
Fixed fornecido como argumento.
*/
Fixed::Fixed(const Fixed &rhs)
{
    *this = rhs;
}

/*
Construtor com Inteiro (Fixed::Fixed(const int intValue)): Inicializa um objeto Fixed com o valor 
_value igual ao inteiro fornecido, convertido para fixo.

A expressão intValue << _fractionalBits é um exemplo de operador shift bitwise, onde << é o operador 
de deslocamento para a esquerda.

O operador << desloca todos os bits para a esquerda pelo número especificado após ele.

_fractionalBits é o número de bits que queremos deslocar. Supondo que _fractionalBits seja igual a 8, 
então 0 << 8 significa que estamos deslocando todos os bits de 0 oito posições para a esquerda.
*/
Fixed::Fixed(const int intValue) : _value(intValue << _fractionalBits) {}

/*
Construtor com Ponto Flutuante (Fixed::Fixed(const float floatValue)): Inicializa um objeto Fixed 
com o valor _value igual ao ponto flutuante fornecido, convertido para fixo.
floatValue * (1 << _fractionalBits): Multiplica o valor de ponto flutuante floatValue pelo valor 
de _fractionalBits (o número de bits para representar a parte fracionária). Isso efetivamente move a 
vírgula do valor floatValue para a esquerda, convertendo-o em uma representação de ponto fixo.
roundf(...): Arredonda o valor resultante para o inteiro mais próximo. Isso é feito usando a função 
roundf() da biblioteca padrão, que retorna o valor arredondado.
static_cast<int>(...): Converte o valor arredondado de volta para um tipo inteiro. Isso é necessário 
porque a variável _value é do tipo inteiro.
_value = ...: Atribui o valor convertido à variável _value, que é um membro da classe Fixed. 
Este valor representa a representação fixa do número de ponto flutuante.
*/
Fixed::Fixed(const float floatValue) : _value(static_cast<int>(roundf(floatValue * (1 << _fractionalBits)))) {}

// Destrutor (Fixed::~Fixed()): Destrói um objeto Fixed.
Fixed::~Fixed() {}

/*
Operador de Atribuição (Fixed& Fixed::operator=(const Fixed& other)): Sobrecarrega o operador de 
atribuição para permitir a cópia dos membros de um objeto Fixed para outro.
*/
Fixed& Fixed::operator=(const Fixed& other)
{
    this->setRawBits(other.getRawBits());
    return (*this);
}

/*
Operadores de Comparação (bool Fixed::operator>(const Fixed& other), bool 
Fixed::operator<(const Fixed& other), etc.): Sobrecarrega os operadores de comparação para comparar 
dois objetos Fixed.
*/
bool Fixed::operator>(const Fixed& other) const
{
    return (_value > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
    return (_value < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (_value >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const 
{
    return (_value <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
    return (_value == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (_value != other.getRawBits());
}

/*
Operadores Aritméticos (Fixed Fixed::operator+(const Fixed& other), 
Fixed Fixed::operator-(const Fixed& other), etc.): Sobrecarrega os operadores 
aritméticos para realizar operações matemáticas entre dois objetos Fixed.
*/
Fixed Fixed::operator+(const Fixed& other) const
{
    return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return (this->toFloat() / other.toFloat());
}

/*
Operadores de Incremento e Decremento (Fixed& Fixed::operator++(), Fixed Fixed::operator++(int), 
etc.): Sobrecarrega os operadores de incremento e decremento para modificar o valor de um objeto Fixed.
*/
Fixed& Fixed::operator++(void)
{
    ++_value;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++(*this);
    return (temp);
}

Fixed& Fixed::operator--()
{
    --_value;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --(*this);
    return (temp);
}
// Método Estático min: Retorna o menor valor entre dois objetos Fixed.
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

// Método Estático max: Retorna o maior valor entre dois objetos Fixed.
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

int Fixed::getRawBits(void) const
{
    return (_value);
}

void Fixed::setRawBits(int const _value)
{
    this->_value = _value;
}

float Fixed::toFloat(void) const
{
    return ((float)getRawBits() / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return (getRawBits() >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
