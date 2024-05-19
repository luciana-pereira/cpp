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

PmergeMe::PmergeMe(void) {} // Construtor padrão da classe PmergeMe, não realiza nenhuma operação.

PmergeMe::PmergeMe(PmergeMe const &others) { // Construtor de cópia da classe PmergeMe
	*this = others; // Copia os atributos do objeto 'others' para o objeto atual
}

PmergeMe::~PmergeMe(void) {} // Destrutor da classe PmergeMe, não realiza nenhuma operação.

PmergeMe& PmergeMe::operator=(PmergeMe const &others) { // Operador de atribuição da classe PmergeMe
	(void)others; // Suprime o aviso de variável não utilizada
	return (*this); // Retorna uma referência para o objeto atual
}

template<typename Container>
void PmergeMe::mergeInsertSort(Container& container) { // Função de classificação por mesclagem e inserção
	if (container.size() <= 1) { // Verifica se o contêiner possui 1 elemento ou menos
		return; // Se sim, não há nada para classificar, então retorna
	}

	typename Container::iterator mid = container.begin(); // Define um iterador para o meio do contêiner
	std::advance(mid, container.size() / 2); // Avança o iterador para a posição do meio

	Container left(container.begin(), mid); // Cria um contêiner 'left' com os elementos da esquerda
	Container right(mid, container.end()); // Cria um contêiner 'right' com os elementos da direita

	mergeInsertSort(left); // Chama a função recursivamente para classificar o contêiner 'left'
	mergeInsertSort(right); // Chama a função recursivamente para classificar o contêiner 'right'

	container.clear(); // Limpa o contêiner original
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(container)); // Mescla os contêineres 'left' e 'right' no contêiner original
}

template<typename Container>
void PmergeMe::printContainer(const std::string& message, const Container& container) { // Função para imprimir o conteúdo de um contêiner
	std::cout << message; // Imprime a mensagem fornecida
	typename Container::const_iterator it; // Define um iterador constante para percorrer o contêiner
	for (it = container.begin(); it != container.end(); ++it) { // Loop sobre todos os elementos do contêiner
		std::cout << " " << *it; // Imprime cada elemento separado por um espaço
	}
	std::cout << std::endl; // Imprime uma nova linha no final
}

template<typename Container>
void PmergeMe::measureTimeAndSort(const std::string& containerName, Container& container) { // Função para medir o tempo de execução da ordenação de um contêiner
	std::clock_t start = std::clock(); // Obtém o tempo de início da execução
	mergeInsertSort(container); // Chama a função de classificação
	std::clock_t end = std::clock(); // Obtém o tempo de término da execução
	double duration = (end - start) / (double)CLOCKS_PER_SEC * 1000000.0; // Calcula a duração da execução em microssegundos

	if (containerName == "std::deque") { // Verifica se o contêiner é um deque
		printContainer("After:", container); // Se for, imprime o conteúdo do contêiner após a ordenação
	}

	std::cout << "Time to process a range of " << container.size() << " elements with " << containerName << " : " << duration << " us" << std::endl; // Imprime o tempo de execução
}

template<typename Container>
bool PmergeMe::hasDuplicates(const Container& container) { // Função para verificar se há duplicatas em um contêiner
	std::list<int> seen; // Cria uma lista para armazenar os elementos já vistos
	typename Container::const_iterator it; // Define um iterador constante para percorrer o contêiner
	for (it = container.begin(); it != container.end(); ++it) { // Loop sobre todos os elementos do contêiner
		if (std::find(seen.begin(), seen.end(), *it) != seen.end()) { // Verifica se o elemento já foi visto
			return (true); // Se sim, retorna true indicando a presença de duplicatas
		}
		seen.push_back(*it); // Adiciona o elemento à lista de elementos vistos
	}
	return (false); // Se não houver duplicatas, retorna false
}

void PmergeMe::sortAndPrint(const std::deque<int>& sequence) { // Função para ordenar e imprimir uma sequência armazenada em um deque
	if (hasDuplicates(sequence)) { // Verifica se há duplicatas na sequência
		std::cerr << "Error: Duplicate numbers found in the sequence" << std::endl; // Se sim, imprime uma mensagem de erro
		return; // Retorna sem fazer nada mais
	}

	std::deque<int> containerDeque = sequence; // Cria uma cópia da sequência em um deque
	std::list<int> containerList(sequence.begin(), sequence.end()); // Cria uma lista a partir da sequência

	printContainer("Before:", sequence); // Imprime a sequência antes da ordenação

	measureTimeAndSort("std::deque", containerDeque); // Mede o tempo de execução da ordenação para o deque
	measureTimeAndSort("std::list", containerList); // Mede o tempo de execução da ordenação para a lista
}

void PmergeMe::sortAndPrint(const std::list<int>& sequence) {
	if (hasDuplicates(sequence)) { // Verifica se há números duplicados na sequência
		std::cerr << "Error: Duplicate numbers found in the sequence" << std::endl; // Imprime uma mensagem de erro
		return; // Retorna sem prosseguir se houver duplicatas
	}

	std::deque<int> containerDeque(sequence.begin(), sequence.end()); // Cria um deque com os elementos da sequência
	std::list<int> containerList = sequence; // Cria uma lista com os elementos da sequência

	printContainer("Before:", sequence); // Imprime a sequência antes da ordenação

	measureTimeAndSort("std::deque", containerDeque); // Mede o tempo de execução e ordena o deque
	measureTimeAndSort("std::list", containerList); // Mede o tempo de execução e ordena a lista
}
