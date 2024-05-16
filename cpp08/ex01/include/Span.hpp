/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 04:01:09 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/16 06:06:39 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <vector>
#include <ctime>

class Span {
public:
	// Construtor padrão
	Span(void);
	// Construtor com limite de tamanho N
	Span(unsigned int N);
	// Construtor de cópia
	Span(Span const &other);
	// Destrutor
	~Span(void);
	// Sobrecarga do operador de atribuição
	Span &operator=(Span const &other);

	// Adiciona um número à lista de números
	void		addNumber(int number);
	// Calcula o menor intervalo entre os números
	long int	shortestSpan(void);
	// Calcula o maior intervalo entre os números
	long int	longestSpan(void);
	// Imprime todos os números armazenados
	void		printNumbers(void) const;

	// Adiciona um intervalo de números à lista de números
	template<typename T>
	void		addRangeOfNumbers(T a, T b) {
		// Verifica se há espaço suficiente para adicionar todos os números do intervalo
		if (std::distance(a, b) > this->_N - (long long)this->_numbers.size()) {
			throw std::exception();
		} 
		
		// Adiciona os números do intervalo à lista de números
		while (a != b) {
			this->_numbers.push_back(*a);
			a++;
		}
	}

private:
	unsigned int _N; // Limite de tamanho
	std::vector<int> _numbers; // Lista de números armazenados
};

#endif
