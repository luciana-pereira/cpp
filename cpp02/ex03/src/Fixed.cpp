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
Construtor Padrão (Fixed::Fixed(void)): Inicializa um objeto Fixed com o valor _value igual a 0.

Construtor de Cópia (Fixed::Fixed(const Fixed &rhs)): Cria um novo objeto Fixed a partir de outro objeto
Fixed fornecido como argumento.

Construtor com Inteiro (Fixed::Fixed(const int intValue)): Inicializa um objeto Fixed com o valor 
_value igual ao inteiro fornecido, convertido para fixo.

Construtor com Ponto Flutuante (Fixed::Fixed(const float floatValue)): Inicializa um objeto Fixed 
com o valor _value igual ao ponto flutuante fornecido, convertido para fixo.

Destrutor (Fixed::~Fixed()): Destrói um objeto Fixed.

Operador de Atribuição (Fixed& Fixed::operator=(const Fixed& other)): Sobrecarrega o operador de 
atribuição para permitir a cópia dos membros de um objeto Fixed para outro.

Operadores de Comparação (bool Fixed::operator>(const Fixed& other), bool 
Fixed::operator<(const Fixed& other), etc.): Sobrecarrega os operadores de comparação para comparar dois objetos Fixed.

Operadores Aritméticos (Fixed Fixed::operator+(const Fixed& other), Fixed Fixed::operator-(const Fixed& other), etc.): Sobrecarrega os operadores aritméticos para realizar operações matemáticas entre dois objetos Fixed.

Operadores de Incremento e Decremento (Fixed& Fixed::operator++(), Fixed Fixed::operator++(int), etc.): Sobrecarrega os operadores de incremento e decremento para modificar o valor de um objeto Fixed.

Método Estático min: Retorna o menor valor entre dois objetos Fixed.

Método Estático max: Retorna o maior valor entre dois objetos Fixed.

Método getRawBits: Retorna o valor armazenado no objeto Fixed.

Método setRawBits: Define o valor armazenado no objeto Fixed.

Método toFloat: Converte o valor armazenado no objeto Fixed para um ponto flutuante.

Método toInt: Converte o valor armazenado no objeto Fixed para um inteiro.

Sobrecarga do Operador de Saída (std::ostream& operator<<(std::ostream& out, const Fixed& fixed)): Permite a saída de um objeto Fixed para um fluxo de saída (como std::cout), convertendo o valor para ponto flutuante.

Esse código implementa uma classe Fixed que representa um número de ponto fixo e sobrecarrega diversos operadores para permitir operações matemáticas e comparações entre objetos Fixed.
*/
#include "../include/Fixed.hpp"
 /
Fixed::Fixed(void) : _value(0) {}

Fixed::Fixed(const Fixed &rhs)
{
    *this = rhs;
}

Fixed::Fixed(const int intValue) : _value(intValue << _fractionalBits) {}

Fixed::Fixed(const float floatValue) : _value(static_cast<int>(roundf(floatValue * (1 << _fractionalBits)))) {}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other)
{
    this->setRawBits(other.getRawBits());
    return (*this);
}

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

// const Fixed& Fixed::min(Fixed& a, Fixed& b)
// {
//     if (a.getRawBits() < b.getRawBits())
// 		return (a);
// 	return (b);
// }

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

// const Fixed& Fixed::max(Fixed& a, Fixed& b)
// {
//     if (a.getRawBits() > b.getRawBits())
// 		return (a);
// 	return (b);
// }

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
