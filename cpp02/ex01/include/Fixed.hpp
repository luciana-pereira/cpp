/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:56:15 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 02:45:59 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

// Classe chamada Fixed, que representa números de ponto fixo. 

class	Fixed
{
private:
	int	_value; // Armazena o valor do número de ponto fixo.
	/*
 	Define o número de bits usados para representar a parte fracionária do número de ponto fixo. 
  	É declarado como static const para ser compartilhado por todas as instâncias da classe.
 	*/
	static const int	_fractionalBits = 8;
public:
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	~Fixed();
	float	toFloat(void) const;
	int		toInt(void) const;
	Fixed&	operator=(const Fixed& other);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

/*
Declaração da Função de Saída:
Sobrecarga do operador de inserção (<<) fora da classe Fixed. Isso permite que objetos da classe Fixed sejam 
inseridos em fluxos de saída, como std::cout, permitindo sua exibição.

A sobrecarga do operador << está fora da classe Fixed porque é uma função global e não precisa acessar membros privados da classe. 
Isso torna a implementação mais limpa e separa claramente as operações de entrada/saída da lógica interna da classe.
*/
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
