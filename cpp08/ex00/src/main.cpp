/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 04:01:09 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/15 05:50:32 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp" // Inclui o arquivo de cabeçalho easyfind.hpp

int	main(void) {
	try {
		std::cout << "\n======== TESTING EASYFIND FUNCTION | VECTOR ========\n" << std::endl;

		std::vector<int> myVector; // Cria um vetor de inteiros

		for (int i = 0; i < 5; i++) { // Preenche o vetor com valores de 0 a 4
			myVector.push_back(i);
		}

		int valueToFindInVector = 3; // Define o valor a ser encontrado no vetor
		std::vector<int>::iterator vectorResult = easyfind(myVector, valueToFindInVector); // Encontra o valor no vetor
		std::cout << "Value " << valueToFindInVector << " found at position " << std::distance(myVector.begin(), vectorResult) << std::endl; // Exibe a posição do valor no vetor

		valueToFindInVector = 8; // Define um novo valor a ser encontrado no vetor
		vectorResult = easyfind(myVector, valueToFindInVector); // Tenta encontrar o novo valor no vetor
		std::cout << "Value " << valueToFindInVector << " found at position " << std::distance(myVector.begin(), vectorResult) << std::endl; // Exibe a posição do valor no vetor
	} catch (const std::exception& e) { // Captura exceções
		std::cerr << "Exception: " << e.what() << std::endl; // Exibe a mensagem de exceção
	}

	std::cout << "\n======== TESTING EASYFIND FUNCTION | LIST ========\n" << std::endl;
	try {
		std::list<int> myList; // Cria uma lista de inteiros

		for (int i = 0; i < 10; i++) { // Preenche a lista com valores de 0 a 9
			myList.push_back(i);
		}

		int valueToFindInList = 5; // Define o valor a ser encontrado na lista
		std::list<int>::iterator listResult = easyfind(myList, valueToFindInList); // Encontra o valor na lista
		std::cout << "Value " << valueToFindInList << " found at position " << std::distance(myList.begin(), listResult) << std::endl; // Exibe a posição do valor na lista

		valueToFindInList = 42; // Define um novo valor a ser encontrado na lista
		listResult = easyfind(myList, valueToFindInList); // Tenta encontrar o novo valor na lista
		std::cout << "Value " << valueToFindInList << " found at position " << std::distance(myList.begin(), listResult) << std::endl; // Exibe a posição do valor na lista
	} catch (const std::exception& e) { // Captura exceções
		std::cerr << "Exception: " << e.what() << std::endl; // Exibe a mensagem de exceção
		std::cout << std::endl; // Pula uma linha
	}
	
	return (0); // Retorna 0 para indicar que o programa foi executado com sucesso
}
