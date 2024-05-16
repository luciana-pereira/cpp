/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:20:53 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/16 21:13:53 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"

int main(void)
{
	// Imprime uma mensagem indicando o início dos testes da criação e operações básicas da MutantStack
	std::cout << "Testing MutantStack creation and basic operations | PDF" << std::endl;

	// Cria uma instância da MutantStack<int> chamada mstack
	MutantStack<int> mstack;

	// Adiciona elementos à pilha mstack
	mstack.push(5);
	mstack.push(17);

	// Imprime o elemento do topo da pilha mstack
	std::cout << "Top element of mstack: " << mstack.top() << std::endl;

	// Remove o elemento do topo da pilha mstack
	mstack.pop();
	std::cout << std::endl;

	// Imprime o tamanho da pilha mstack após a operação de pop
	std::cout << "Size of mstack after pop: " << mstack.size() << std::endl;

	// Adiciona mais elementos à pilha mstack
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << std::endl;

	// Itera através da MutantStack usando iteradores
	std::cout << "Iterating through MutantStack:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// Testa a conversão de MutantStack para std::stack
	std::stack<int> s(mstack);

	// Outro teste das operações básicas de criação e MutantStack
	std::cout << "\nAnother test of MutantStack's basic creation and operations" << std::endl;
	MutantStack<int> mutantStack;
	mutantStack.push(10);
	mutantStack.push(20);
	mutantStack.push(30);

	// Imprime os elementos da MutantStack mutantStack
	std::cout << "MutantStack:";
	for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

	// Testa as funções de iteração constante
	std::cout << "\nTesting constant iteration functions" << std::endl;
	const MutantStack<int>& constStack = mutantStack;
	std::cout << "Const MutantStack:";
	for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

	// Testa a operação de rollback da MutantStack
	std::cout << "\nTesting MutantStack rollback" << std::endl;
	std::cout << "Reverse MutantStack:";
	for (MutantStack<int>::reverse_iterator it = mutantStack.rbegin(); it != mutantStack.rend(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

	// Testa as funções de iteração reversa constante
	std::cout << "\nTesting the reverse constant iteration functions" << std::endl;
	std::cout << "Const Reverse MutantStack:";
	for (MutantStack<int>::const_reverse_iterator it = constStack.rbegin(); it != constStack.rend(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

	// Testa a cópia da MutantStack
	std::cout << "\nTesting the MutantStack copy" << std::endl;
	MutantStack<int> mutantStackCopy = mutantStack;
	std::cout << "MutantStack Copy:";
	while (!mutantStackCopy.empty()) {
		std::cout << ' ' << mutantStackCopy.top();
		mutantStackCopy.pop();
	}
	std::cout << std::endl;

	// Testa a MutantStack com tipos de dados complexos
	std::cout << "\nTesting MutantStack with complex data types" << std::endl;
	MutantStack<std::vector<int> > complexStack;
	complexStack.push(std::vector<int>());
	complexStack.top().push_back(1);
	complexStack.top().push_back(2);
	complexStack.top().push_back(3);

	// Imprime os elementos da MutantStack complexStack
	std::cout << "Complex MutantStack:" << std::endl;
	for (MutantStack<std::vector<int> >::const_iterator it = complexStack.begin(); it != complexStack.end(); ++it) {
		for (std::vector<int>::const_iterator vecIt = it->begin(); vecIt != it->end(); ++vecIt) {
			std::cout << *vecIt << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
