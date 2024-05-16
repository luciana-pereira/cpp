/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 04:01:09 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/16 06:07:20 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

int	main(void) {
	try {
		std::cout << "\n=============== TESTING PDF ===============\n" << std::endl;
		Span sp = Span(5); // Cria um objeto Span com limite de tamanho 5
		
			sp.addNumber(6); // Adiciona o número 6
			sp.addNumber(3); // Adiciona o número 3
			sp.addNumber(17); // Adiciona o número 17
			sp.addNumber(9); // Adiciona o número 9
			sp.addNumber(11); // Adiciona o número 11
			
			std::cout << sp.shortestSpan() << std::endl; // Exibe a menor diferença entre os números
			std::cout << sp.longestSpan() << std::endl; // Exibe a maior diferença entre os números
			
			std::cout << "======== TEST WITH HIGHEST NUMBER 1 =======\n" << std::endl;
			Span sp1 = Span(10000);
			
			for (int i = 0; i < 10000; i++) {
				sp1.addNumber(i); // Adiciona números de 0 a 9999
			}
			std::cout << "Shortest Span: " << sp1.shortestSpan() << std::endl; // Exibe a menor diferença entre os números
			std::cout << "Longest Span: " << sp1.longestSpan() << std::endl; // Exibe a maior diferença entre os números
			
			std::cout << "\n======== TEST WITH HIGHEST NUMBER 2 =======\n" << std::endl;
			
			Span sp2 = Span(100000);
			
			for (int i = 0; i < 100000; i++) {
				sp2.addNumber(i); // Adiciona números de 0 a 99999
			}
		
			std::cout << "Shortest Span: " << sp1.shortestSpan() << std::endl; // Exibe a menor diferença entre os números
			std::cout << "Longest Span: " << sp1.longestSpan() << std::endl; // Exibe a maior diferença entre os números
			
			std::cout << "\n====== TESTING WITH REPEATED NUMBERS ======\n" << std::endl;
			Span sp4 = Span(5);
			
			sp4.addNumber(10); // Adiciona o número 10
			sp4.addNumber(20); // Adiciona o número 20
			sp4.addNumber(30); // Adiciona o número 30
			sp4.addNumber(10); // Adiciona o número 10 novamente
			sp4.addNumber(40); // Adiciona o número 40
			
			std::cout << "Shortest Span: " << sp4.shortestSpan() << std::endl; // Exibe a menor diferença entre os números
			std::cout << "Longest Span: " << sp4.longestSpan() << std::endl; // Exibe a maior diferença entre os números
			
			std::cout << "\n========= TEST WITH RANDOM NUMBERS ========\n" << std::endl;
			Span sp3 = Span(10);
			
			srand(time(NULL));
			for (int i = 0; i < 10; ++i) {
				sp3.addNumber(rand() % 100); // Adiciona números aleatórios entre 0 e 99
			}
			std::cout << "Shortest Span: " << sp3.shortestSpan() << std::endl; // Exibe a menor diferença entre os números
			std::cout << "Longest Span: " << sp3.longestSpan() << std::endl; // Exibe a maior diferença entre os números
			sp3.printNumbers(); // Exibe os números armazenados
		
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl; // Exibe exceções
		}
		
		try {
			std::cout << "\n======= INIT TEST | addRangeOfNumbers =====\n" << std::endl;
		
			
			std::cout << "\nTEST WITH HIGHEST NUMBER 1 | addRangeOfNumbers\n" << std::endl;
			
			Span highestNumber = Span(10000);
			std::vector<int> rangeNumber;
			
			for (int i = 1; i < 10000; ++i) {
				rangeNumber.push_back(i);
			}
		
			highestNumber.addRangeOfNumbers(rangeNumber.begin(), rangeNumber.end()); // Adiciona uma faixa de números de 1 a 9999
			
			std::cout << "Shortest Span: " << highestNumber.shortestSpan() << std::endl; // Exibe a menor diferença entre os números
			std::cout << "Longest Span: " << highestNumber.longestSpan() << std::endl; // Exibe a maior diferença entre os números
		
			std::cout << "\nTEST WITH HIGHEST NUMBER 2 | addRangeOfNumbers\n" << std::endl;
			
			Span highestNumber1 = Span(100000);
			std::vector<int> rangeNumber1;
			
			for (int i = 0; i < 100000; i++) {
				rangeNumber1.push_back(i);
			}
		
			highestNumber1.addRangeOfNumbers(rangeNumber1.begin(), rangeNumber1.end()); // Adiciona uma faixa de números de 0 a 99999
		
			std::cout << "Shortest Span: " << highestNumber1.shortestSpan() << std::endl; // Exibe a menor diferença entre os números
			std::cout << "Longest Span: " << highestNumber1.longestSpan() << std::endl; // Exibe a maior diferença entre os números
		
			std::cout << "\nTESTS RANDOM NUMBERS | addRangeOfNumbers \n" << std::endl;
		
			Span highestNumber2 = Span(10);
			std::vector<int> rangeNumber2;
			
			srand(time(NULL));
			for (int i = 0; i < 10; ++i) {
				rangeNumber2.push_back(rand() % 100); // Adiciona números aleatórios entre 0 e 99
			}
		
			highestNumber2.addRangeOfNumbers(rangeNumber2.begin(), rangeNumber2.end());
		
			std::cout << "Shortest Span: " << highestNumber2.shortestSpan() << std::endl; // Exibe a menor diferença entre os números
			std::cout << "Longest Span: " << highestNumber2.longestSpan() << std::endl; // Exibe a maior diferença entre os números
			highestNumber2.printNumbers(); // Exibe os números armazenados
			std::cout << std::endl;
			
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl; // Exibe exceções
		}
		
		return (0);
}
