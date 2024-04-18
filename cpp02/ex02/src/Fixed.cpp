/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 03:01:30 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 07:19:36 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

/*
Aqui implentei uma classe Fixed que representa um número de ponto fixo e sobrecarrega 
diversos operadores para permitir operações matemáticas e comparações entre objetos Fixed
*/

// Construtor Padrão (Fixed::Fixed(void)): Inicializa um objeto Fixed com o valor _value igual a 0.
Fixed::Fixed() : _value(0) {}

/*
Construtor de Cópia (Fixed::Fixed(const Fixed &rhs)): Cria um novo objeto Fixed a partir de outro objeto 
Fixed fornecido como argumento.
*/ 
Fixed::Fixed(const Fixed& other)
{
	Fixed::operator=(other);
}

/*
Construtor com Inteiro (Fixed::Fixed(const int intValue)): Inicializa um objeto Fixed com o valor _value 
igual ao inteiro fornecido, convertido para fixo.
*/
Fixed::Fixed(const int intValue) : value(intValue << fractionalBits) {}

/*
Construtor com Ponto Flutuante (Fixed::Fixed(const float floatValue)): Inicializa um objeto Fixed com o 
valor _value igual ao ponto flutuante fornecido, convertido para fixo.
*/
Fixed::Fixed(const float floatValue) : value(static_cast<int>(roundf(floatValue * (1 << fractionalBits)))) {}

/*
Destrutor (Fixed::~Fixed()): Destrói um objeto Fixed.
*/
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
Operadores de Comparação (bool Fixed::operator>(const Fixed& other), 
bool Fixed::operator<(const Fixed& other), etc.): Sobrecarrega os operadores de comparação para 
comparar dois objetos Fixed
*/
bool Fixed::operator>(const Fixed& other) const
{
    return (value > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
    return (value < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (value >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const 
{
    return (value <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
    return (value == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (value != other.getRawBits());
}

/*
Operadores Aritméticos (Fixed Fixed::operator+(const Fixed& other), 
Fixed Fixed::operator-(const Fixed& other), etc.): Sobrecarrega os operadores aritméticos para 
realizar operações matemáticas entre dois objetos Fixed.
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
Operadores de Incremento e Decremento (Fixed& Fixed::operator++(), Fixed Fixed::operator++(int), etc.): 
Sobrecarrega os operadores de incremento e decremento para modificar o valor de um objeto Fixed
*/
Fixed& Fixed::operator++(void)
{
    ++value;
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
    --value;
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

// Método getRawBits: Retorna o valor armazenado no objeto Fixed
int Fixed::getRawBits(void) const
{
    return (value);
}

// Método setRawBits: Define o valor armazenado no objeto Fixed.
void Fixed::setRawBits(int const value)
{
    this->value = value;
}

// Método toFloat: Converte o valor armazenado no objeto Fixed para um ponto flutuante
float Fixed::toFloat(void) const
{
    return ((float)getRawBits() / (float)(1 << fractionalBits));
}

// Método toInt: Converte o valor armazenado no objeto Fixed para um inteiro.
int Fixed::toInt(void) const
{
    return (getRawBits() >> fractionalBits);
}

/*
Sobrecarga do Operador de Saída (std::ostream& operator<<(std::ostream& out, const Fixed& fixed)): 
Permite a saída de um objeto Fixed para um fluxo de saída (como std::cout), convertendo o valor para 
ponto flutuante.
*/
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
