/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:36:00 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/04 01:48:33 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"

Base*	generate() {
	/*
 	Gera um número aleatório entre 0 e 2. A função rand() retorna um valor aleatório, e % 3 é usado para garantir 
  	que o valor esteja dentro do intervalo desejado.
 	*/
	int	randomValue = rand() % 3;
	
	// Usada para selecionar uma ação com base no valor gerado aleatoriamente acima.
	switch (randomValue) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
		default: return (NULL);
	}
	
}

/*
dynamic_cast: Esta função é usada para verificar se o tipo de um objeto apontado por p é uma classe derivada de Base. 
Se for, um ponteiro para o objeto convertido é retornado; caso contrário, é retornado um ponteiro nulo (NULL).
*/
void	identify(Base* p) {
	/*
 	Se dynamic_cast retornar um ponteiro diferente de NULL, significa que o objeto é de uma classe derivada específica (A, B ou C), 
  	*/
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

/*
dynamic_cast: Esta função é usada para verificar se o tipo de um objeto apontado por p é uma classe derivada de Base. 
Se for, um ponteiro para o objeto convertido é retornado; caso contrário, é retornado um ponteiro nulo (NULL).
*/
void identify(Base& p) {
	/*
 	A lógica é a mesma que na função identify(Base* p), mas em vez de verificar o tipo do objeto apontado por p, 
  	ela verifica o tipo do objeto referenciado por p
  	*/
	if (dynamic_cast<A*>(&p) != NULL) {
		std::cout << "A" << std::endl;
		return ;
	}

	if (dynamic_cast<B*>(&p) != NULL) {
		std::cout << "B" << std::endl;
		return ;
	}

	if (dynamic_cast<C*>(&p) != NULL) {
		std::cout << "C" << std::endl;
		return ;
	}

	std::cout << "Unknown type" << std::endl;
}
/*
A função generate() gera um objeto aleatório do tipo A, B ou C, enquanto as funções identify verificam e identificam o tipo do objeto gerado.
*/
