#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
private:
	int	fixedValue;
	static const int	fractionalBits = 8;
public:
	Fixed(void);
	Fixed(const Fixed& other);
	~Fixed(void);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	Fixed& operator=(const Fixed &other);
};

#endif
