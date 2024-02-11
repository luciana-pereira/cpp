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

const int	Fixed::fractionalBits = 8;

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed& other)
{
	Fixed::operator=(other);
}

Fixed::Fixed(const int intValue) : value(intValue << fractionalBits) {}

Fixed::Fixed(const float floatValue) : value(static_cast<int>(roundf(floatValue * (1 << fractionalBits)))) {}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other)
{
    this->setRawBits(other.getRawBits());
    return (*this);
}

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
    return (value);
}

void Fixed::setRawBits(int const value)
{
    this->value = value;
}

float Fixed::toFloat(void) const
{
    return ((float)getRawBits() / (float)(1 << fractionalBits));
}

int Fixed::toInt(void) const
{
    return (getRawBits() >> fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
