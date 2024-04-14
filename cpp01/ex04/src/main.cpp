#include "../include/FileOperations.hpp"
#include "../include/StringOperations.hpp"

int main(int argc, char *argv[])
{
	/*
 	Verifica-se se o número de argumentos fornecidos na linha de comando é igual a 4 
  	(o nome do executável mais três argumentos). Se não for, exibe uma mensagem de erro 
   	indicando o uso correto do programa e retorna 1, indicando um erro.
 	*/
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	// Se o número de argumentos estiver correto, os argumentos são atribuídos às variáveis 
	std::string inputFilename = argv[1];
	std::string searchString = argv[2];
	std::string replacementString = argv[3];
	// É criada uma string fileContent para armazenar o conteúdo do arquivo de entrada.
	std::string fileContent;
	/*
 	 lê o conteúdo do arquivo de entrada. Se a função retornar um valor diferente de zero, 
   	significa que ocorreu um erro ao abrir o arquivo, então o programa retorna 1.
	*/
	if (FileOperations::readInputFile(inputFilename.c_str(), fileContent) != 0)
	{
		return (1);
	}
	/* 
 	modifiedContent criada para armazenar o conteúdo do arquivo de entrada com as substituições 
	realizadas.
	*/
	std::string modifiedContent;
	/*
	StringOperations::replaceOccurrences Para substituir todas as ocorrências da substring de busca 
	pela substring de substituição. Se a função retornar false, significa que a substring de busca 
 	não foi encontrada no conteúdo do arquivo, então uma mensagem de erro é exibida e o programa 
  	retorna 1.
	*/
	if (!StringOperations::replaceOccurrences(fileContent, searchString, replacementString, modifiedContent)) {
		std::cerr << "Error: String '" << searchString << "' not found in the file." << std::endl;
		return (1);
	}
	// Gera o nome do arquivo de saída, que é baseado no nome do arquivo de entrada com a adição de ".replace".
	std::string outputFilename = FileOperations::generateOutputFileName(inputFilename);
	/*
 	FileOperations::writeOutputFile para escrever o conteúdo modificado no arquivo de saída. 
  	Se a função retornar um valor diferente de zero, indica que ocorreu um erro ao escrever 
   	no arquivo, então o programa retorna 1.
 	*/
	if (FileOperations::writeOutputFile(outputFilename, modifiedContent) != 0)
	{
		return (1);
	}
	/*
 	Se todas as operações forem bem-sucedidas, exibe uma mensagem indicando que a substituição 
  	foi feita com sucesso e que o arquivo de saída foi escrito.
 	*/
	std::cout << "Replacement successful. Output written to: " << outputFilename << std::endl;
	return (0);
}
