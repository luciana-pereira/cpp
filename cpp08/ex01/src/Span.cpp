/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 04:01:09 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/16 06:05:16 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
Span::Span(void) : _N(0) { }

Span::Span(unsigned int N) : _N(N) {
	_numbers = std::vector<int>(); // Inicializa _numbers como um vetor vazio
}

Span::Span(Span const &other) : _N(other._N) {
	_numbers = other._numbers; // Copia os números de 'other' para '_numbers'
}

Span::~Span(void) {} // Destrutor vazio

Span &Span::operator=(Span const &other) {
	_N = other._N; // Atribui o limite de tamanho de 'other' para '_N'
	_numbers = other._numbers; // Copia os números de 'other' para '_numbers'
	return (*this);
}

void	Span::addNumber(int num) {
	if (_numbers.size() >= _N || _numbers.size() == _N) { // Verifica se a capacidade máxima foi atingida
		throw std::runtime_error("Cannot add more numbers. Span is full."); // Lança uma exceção se a capacidade máxima foi atingida
	}
	_numbers.push_back(num); // Adiciona 'num' ao final de '_numbers'
}

long int	Span::shortestSpan() {
	if (_numbers.size() < 2) { // Verifica se há pelo menos dois números para calcular o intervalo
		throw std::exception(); // Lança uma exceção se não houver números suficientes
	}

	std::sort(_numbers.begin(), _numbers.end()); // Ordena os números em ordem crescente

	std::vector<int>::iterator it = _numbers.begin();
	std::vector<int>::iterator nextIt = it;
	++nextIt;
	
	int minSpan = *nextIt - *it; // Inicializa 'minSpan' com a diferença entre o segundo e o primeiro elemento

	while (nextIt != _numbers.end()) {
		int span = *nextIt - *it; // Calcula a diferença entre o elemento atual e o próximo
		if (span < minSpan) {
			minSpan = span; // Atualiza 'minSpan' se a diferença atual for menor
		}
		it = nextIt;
		nextIt++;
	}

	return (minSpan); // Retorna o menor intervalo
}

long int Span::longestSpan(void) {
	if (_numbers.size() < 2) { // Verifica se há pelo menos dois números para calcular o intervalo
		throw std::exception(); // Lança uma exceção se não houver números suficientes
	}

	std::vector<int>::iterator minVal = std::min_element(_numbers.begin(), _numbers.end()); // Encontra o menor elemento
	std::vector<int>::iterator maxVal = std::max_element(_numbers.begin(), _numbers.end()); // Encontra o maior elemento

	return (*maxVal - *minVal); // Retorna o maior intervalo
}

void	Span::printNumbers() const {
	std::cout << "Numbers stored in Span:"; // Imprime uma mensagem
	for (std::vector<int>::const_iterator it = _numbers.begin(); it != _numbers.end(); ++it) {
		std::cout << " " << *it; // Imprime cada número armazenado em '_numbers'
	}
	std::cout << std::endl; // Pula uma linha após a impressão dos números
}
