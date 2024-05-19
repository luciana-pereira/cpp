/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:57:58 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/19 19:14:43 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe(void) {} // Construtor padr�o da classe PmergeMe, n�o realiza nenhuma opera��o.

PmergeMe::PmergeMe(PmergeMe const &others) { // Construtor de c�pia da classe PmergeMe
	*this = others; // Copia os atributos do objeto 'others' para o objeto atual
}

PmergeMe::~PmergeMe(void) {} // Destrutor da classe PmergeMe, n�o realiza nenhuma opera��o.

PmergeMe& PmergeMe::operator=(PmergeMe const &others) { // Operador de atribui��o da classe PmergeMe
	(void)others; // Suprime o aviso de vari�vel n�o utilizada
	return (*this); // Retorna uma refer�ncia para o objeto atual
}

template<typename Container>
void PmergeMe::mergeInsertSort(Container& container) { // Fun��o de classifica��o por mesclagem e inser��o
	if (container.size() <= 1) { // Verifica se o cont�iner possui 1 elemento ou menos
		return; // Se sim, n�o h� nada para classificar, ent�o retorna
	}

	typename Container::iterator mid = container.begin(); // Define um iterador para o meio do cont�iner
	std::advance(mid, container.size() / 2); // Avan�a o iterador para a posi��o do meio

	Container left(container.begin(), mid); // Cria um cont�iner 'left' com os elementos da esquerda
	Container right(mid, container.end()); // Cria um cont�iner 'right' com os elementos da direita

	mergeInsertSort(left); // Chama a fun��o recursivamente para classificar o cont�iner 'left'
	mergeInsertSort(right); // Chama a fun��o recursivamente para classificar o cont�iner 'right'

	container.clear(); // Limpa o cont�iner original
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(container)); // Mescla os cont�ineres 'left' e 'right' no cont�iner original
}

template<typename Container>
void PmergeMe::printContainer(const std::string& message, const Container& container) { // Fun��o para imprimir o conte�do de um cont�iner
	std::cout << message; // Imprime a mensagem fornecida
	typename Container::const_iterator it; // Define um iterador constante para percorrer o cont�iner
	for (it = container.begin(); it != container.end(); ++it) { // Loop sobre todos os elementos do cont�iner
		std::cout << " " << *it; // Imprime cada elemento separado por um espa�o
	}
	std::cout << std::endl; // Imprime uma nova linha no final
}

template<typename Container>
void PmergeMe::measureTimeAndSort(const std::string& containerName, Container& container) { // Fun��o para medir o tempo de execu��o da ordena��o de um cont�iner
	std::clock_t start = std::clock(); // Obt�m o tempo de in�cio da execu��o
	mergeInsertSort(container); // Chama a fun��o de classifica��o
	std::clock_t end = std::clock(); // Obt�m o tempo de t�rmino da execu��o
	double duration = (end - start) / (double)CLOCKS_PER_SEC * 1000000.0; // Calcula a dura��o da execu��o em microssegundos

	if (containerName == "std::deque") { // Verifica se o cont�iner � um deque
		printContainer("After:", container); // Se for, imprime o conte�do do cont�iner ap�s a ordena��o
	}

	std::cout << "Time to process a range of " << container.size() << " elements with " << containerName << " : " << duration << " us" << std::endl; // Imprime o tempo de execu��o
}

template<typename Container>
bool PmergeMe::hasDuplicates(const Container& container) { // Fun��o para verificar se h� duplicatas em um cont�iner
	std::list<int> seen; // Cria uma lista para armazenar os elementos j� vistos
	typename Container::const_iterator it; // Define um iterador constante para percorrer o cont�iner
	for (it = container.begin(); it != container.end(); ++it) { // Loop sobre todos os elementos do cont�iner
		if (std::find(seen.begin(), seen.end(), *it) != seen.end()) { // Verifica se o elemento j� foi visto
			return (true); // Se sim, retorna true indicando a presen�a de duplicatas
		}
		seen.push_back(*it); // Adiciona o elemento � lista de elementos vistos
	}
	return (false); // Se n�o houver duplicatas, retorna false
}

void PmergeMe::sortAndPrint(const std::deque<int>& sequence) { // Fun��o para ordenar e imprimir uma sequ�ncia armazenada em um deque
	if (hasDuplicates(sequence)) { // Verifica se h� duplicatas na sequ�ncia
		std::cerr << "Error: Duplicate numbers found in the sequence" << std::endl; // Se sim, imprime uma mensagem de erro
		return; // Retorna sem fazer nada mais
	}

	std::deque<int> containerDeque = sequence; // Cria uma c�pia da sequ�ncia em um deque
	std::list<int> containerList(sequence.begin(), sequence.end()); // Cria uma lista a partir da sequ�ncia

	printContainer("Before:", sequence); // Imprime a sequ�ncia antes da ordena��o

	measureTimeAndSort("std::deque", containerDeque); // Mede o tempo de execu��o da ordena��o para o deque
	measureTimeAndSort("std::list", containerList); // Mede o tempo de execu��o da ordena��o para a lista
}

void PmergeMe::sortAndPrint(const std::list<int>& sequence) {
	if (hasDuplicates(sequence)) { // Verifica se h� n�meros duplicados na sequ�ncia
		std::cerr << "Error: Duplicate numbers found in the sequence" << std::endl; // Imprime uma mensagem de erro
		return; // Retorna sem prosseguir se houver duplicatas
	}

	std::deque<int> containerDeque(sequence.begin(), sequence.end()); // Cria um deque com os elementos da sequ�ncia
	std::list<int> containerList = sequence; // Cria uma lista com os elementos da sequ�ncia

	printContainer("Before:", sequence); // Imprime a sequ�ncia antes da ordena��o

	measureTimeAndSort("std::deque", containerDeque); // Mede o tempo de execu��o e ordena o deque
	measureTimeAndSort("std::list", containerList); // Mede o tempo de execu��o e ordena a lista
}
