/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:19:08 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/10 23:33:24 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

// Criação de objetos da classe Fixed e a realização de operações com eles. 
int	main(void)
{
	// Cria um objeto Fixed chamado a usando o construtor padrão, que inicializa o valor como zero.
	Fixed	a;
	// Cria um objeto Fixed constante b com o valor 10 usando o construtor que aceita um inteiro como parâmetro.
	Fixed const b(10);
	// Cria um objeto Fixed constante c com o valor 42.42 usando o construtor que aceita um float como parâmetro.
	Fixed const c(42.42f);
	// Cria um objeto Fixed constante d com base no objeto b, utilizando o construtor de cópia.
	Fixed const d(b);
	
	// Atribui o valor 1234.4321 ao objeto a, convertendo-o para ponto flutuante.
	a = Fixed(1234.4321f);
	// Imprime os valores dos objetos a, b, c e d 
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	// Imprime os valores dos objetos a, b, c e d como inteiros na saída padrão, usando a função toInt() da classe Fixed.
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	//  o código cria objetos Fixed com diferentes valores, os imprime na tela e verifica se eles podem ser convertidos corretamente para inteiros.
	return (0);
}
