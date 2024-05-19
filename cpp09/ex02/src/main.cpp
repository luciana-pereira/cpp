/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:57:40 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/19 19:10:25 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int main(int argc, char* argv[]) {
	if (argc < 2) { // Verifica se foi fornecido algum argumento
		std::cerr << "Error: No input provided. \nUse: ./PmergeMe <numbers>" << std::endl; // Imprime uma mensagem de erro
		return 1; // Retorna 1 indicando falha
	}

	try {
		std::deque<int> sequence;
		for (int i = 1; i < argc; ++i) { // Loop para processar os argumentos fornecidos
			int num = std::atoi(argv[i]); // Converte o argumento para inteiro
			if (num <= 0) { // Verifica se o número é não positivo
				throw std::invalid_argument("Non-positive integer"); // Lança uma exceção se o número não for positivo
			}
			sequence.push_back(num); // Adiciona o número à sequência
		}

		PmergeMe pmergeme; // Cria uma instância da classe PmergeMe
		pmergeme.sortAndPrint(sequence); // Chama o método sortAndPrint para ordenar e imprimir a sequência
	} catch (const std::exception& e) { // Captura exceções do tipo std::exception
		std::cerr << "Error: " << e.what() << std::endl; // Imprime a mensagem de erro
		return 1; // Retorna 1 indicando falha
	}
	return 0; // Retorna 0 indicando sucesso
}

/*int	main(void) {
	PmergeMe pmergeMe;

	std::cout << "\nTest with an ordered sequence" << std::endl;
	std::deque<int> sequence_ordered;
	sequence_ordered.push_back(1);
	sequence_ordered.push_back(2);
	sequence_ordered.push_back(3);
	sequence_ordered.push_back(4);
	sequence_ordered.push_back(5);
	pmergeMe.sortAndPrint(sequence_ordered);

	std::cout << "\nTest with an inversely ordered sequence" << std::endl;
	std::deque<int> sequence_reversed;
	sequence_reversed.push_back(5);
	sequence_reversed.push_back(4);
	sequence_reversed.push_back(3);
	sequence_reversed.push_back(2);
	sequence_reversed.push_back(1);
	pmergeMe.sortAndPrint(sequence_reversed);

	std::cout << "\nTest with a sequence with repeated elements" << std::endl;
	std::deque<int> sequence_duplicates;
	sequence_duplicates.push_back(1);
	sequence_duplicates.push_back(2);
	sequence_duplicates.push_back(3);
	sequence_duplicates.push_back(2);
	sequence_duplicates.push_back(4);
	sequence_duplicates.push_back(5);
	sequence_duplicates.push_back(3);
	pmergeMe.sortAndPrint(sequence_duplicates);

	std::cout << "\nTest with an empty string" << std::endl;
	std::deque<int> sequence_empty;
	pmergeMe.sortAndPrint(sequence_empty);

	std::cout << "\nTest with a sequence containing a single element" << std::endl;
	std::deque<int> sequence_single_element;
	sequence_single_element.push_back(42);
	pmergeMe.sortAndPrint(sequence_single_element);
	std::cout << std::endl;

	return (0);
}*/
