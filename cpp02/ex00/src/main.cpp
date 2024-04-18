/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:43:12 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/10 21:49:30 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

/*
No teste abaixo retirado do subject, criamos três objetos Fixed (a, b e c),  que demonstra a 
cópia de valores entre eles usando o construtor de cópia e o operador de atribuição, e imprime os 
valores brutos de bits de cada objeto. Isso ajuda a entender como os construtores, destrutores e 
operadores de cópia e atribuição funcionam na classe Fixed.
*/
int main( void )
{
	/*
 	Cria um objeto Fixed chamado a, usando o construtor padrão, 
  	e imprime uma mensagem indicando que o construtor padrão foi chamado e 
   	inicializa a como 0.
	*/ 
	Fixed	a;
	
	/*
 	Cria um objeto Fixed chamado b usando o construtor de cópia, e 
  	imprime uma mensagem indicando que o construtor de cópia foi chamado e 
   	copia o valor de a para b.
 	*/ 
	Fixed	b(a);
	
	/*
 	Cria um objeto Fixed chamado c usando o construtor padrão.
	Imprime uma mensagem indicando que o construtor padrão foi chamado.
	Inicializa o valor de c como 0.
  	*/
	Fixed	c;

	/*
 	Chama o operador de atribuição para atribuir o valor de b para c.
	Imprime uma mensagem indicando que o operador de atribuição foi chamado.
	Copia o valor de b para c
  	*/
	c = b;

	/*
 	Imprime o valor bruto de bits de a.
	Imprime uma mensagem indicando que o método getRawBits foi chamado.
 	*/
	std::cout << a.getRawBits() << std::endl;

	/*
 	Imprime o valor bruto de bits de b.
	Imprime uma mensagem indicando que o método getRawBits foi chamado.
 	*/
	std::cout << b.getRawBits() << std::endl;

	/*
 	Imprime o valor bruto de bits de c.
	Imprime uma mensagem indicando que o método getRawBits foi chamado.
 	*/
	std::cout << c.getRawBits() << std::endl;
	return (0);
}
