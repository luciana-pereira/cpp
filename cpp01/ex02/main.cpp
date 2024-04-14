#include <iostream>
#include <string>

// Lidar com ponteiros e refencias e a sintaxe, ou seja, o programa imprime os endereços de memória 
// e os valores de uma variável std::string, um ponteiro para essa variável e uma referência para ela.

int	main(void)
{
	// -> Declaração de Variáveis:
	//  Inicializa uma variável
	std::string myString = "HI THIS IS BRAIN";
	// Declara um ponteiro e atribui o endereço de memória da variável myString a ele.
	std::string *stringPTR = &myString;
	// Declara uma referência e a inicializa como uma referência para a variável myString.
	std::string &stringREF = myString;

	// -> Impressão dos Endereços de Memória:
	// Imprime o endereço de memória da variável myString.
	std::cout << "Memory address of the string variable: " << &myString << std::endl;
	// Imprime o endereço de memória armazenado no ponteiro stringPTR.
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	// Imprime o endereço de memória da referência stringREF.
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	// -> Impressão dos Valores das Variáveis
	// Imprime o valor armazenado na variável myString
	std::cout << "Value of the string variable: " << myString << std::endl;
	// Imprime o valor apontado pelo ponteiro stringPTR, ou seja, o conteúdo da variável myString
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	// Imprime o valor referenciado pela referência stringREF, que é o conteúdo da variável myString.
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
	return (0);
}
