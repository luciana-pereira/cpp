#include "../include/FileOperations.hpp"

/*
A classe FileOperations que fornece métodos para operações de leitura e escrita de arquivos.
*/

/*
 O método recebe o nome de um arquivo como entrada (filename) e uma referência para uma string fileContent.
 Ele tenta abrir o arquivo especificado para leitura. Se a abertura for bem-sucedida, ele lê o conteúdo 
 do arquivo linha por linha usando std::getline, e cada linha lida é anexada à string fileContent, 
 seguida por um caractere de nova linha. 
 Após a leitura completa do arquivo, o arquivo é fechado e a função retorna 0 para indicar sucesso ou 
 1 se houver algum erro na abertura do arquivo.
*/
int	FileOperations::readInputFile(const char *filename, std::string &fileContent)
{
	std::ifstream inputFileStream(filename);
	if (!inputFileStream.is_open())
	{
		std::cerr << "Error: Failed to open input file!" << std::endl;
		return (1);
	}
	std::string line;
	while (std::getline(inputFileStream, line)) // Se a abertura for bem-sucedida, ele lê o conteúdo
	{
		fileContent += line + "\n"; // cada linha lida é anexada à string fileContent
	}
	inputFileStream.close(); // Após a leitura completa do arquivo, o arquivo é fechado
	return (0);
}

/*
O método recebe o nome de um arquivo de entrada como entrada e retorna o nome do arquivo de saída. 
Ele tenta encontrar a última ocorrência de um ponto no nome do arquivo de entrada usando 
a função find_last_of('.'). Se um ponto for encontrado, ele extrai a parte do nome do arquivo 
antes do ponto e a armazena em outputFilename. Se não houver ponto no nome do arquivo de entrada, 
ele simplesmente copia o nome do arquivo de entrada para outputFilename. 
Em seguida, ele adiciona a extensão ".replace" ao nome do arquivo de saída e o retorna.
*/
std::string	FileOperations::generateOutputFileName(const std::string &inputFilename)
{
	std::size_t dot = inputFilename.find_last_of('.'); // encontrar a última ocorrência de um ponto no nome do arquivo de entrada
	std::string outputFilename;
	if (dot != std::string::npos) {
		outputFilename = inputFilename.substr(0, dot);
	} else {
		outputFilename = inputFilename;
	}
	outputFilename += ".replace";
	return (outputFilename);
}

/*
O método recebe o nome de um arquivo de saída e o conteúdo a ser escrito no arquivo. 
Ele tenta abrir o arquivo especificado para escrita. Se a abertura for bem-sucedida, 
ele escreve o conteúdo no arquivo usando o operador de inserção << do fluxo de saída. 
Após a escrita, o arquivo é fechado e a função retorna 0 para indicar sucesso ou 1 se 
houver algum erro na abertura do arquivo.
*/
int FileOperations::writeOutputFile(const std::string &filename, const std::string &content)
{
	std::ofstream outputFileStream(filename.c_str());
	if (!outputFileStream.is_open()) {
		std::cerr << "Error: Failed to open output file!" << std::endl;
		return (1);
	}
	// escreve o conteúdo no arquivo usando o operador de inserção << do fluxo de saída.
	outputFileStream << content;
	outputFileStream.close();
	return (0);
}
