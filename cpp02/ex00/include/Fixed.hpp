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
	// Declaração das funções membro que retorna o valor bruto de bits do número fixo.
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	// Operador de atribuição, sobrecarga do operador de atribuição da classe Fixed, 
	// que indica que estamos sobrecarregando o operador de atribuição (=) na classe Fixed.
	Fixed& operator=(const Fixed &other);
};

#endif
