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

#include "../include/Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

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
