/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:12:17 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/22 19:34:29 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

#include "../include/BitcoinExchange.hpp"

// Construtor padrão: inicializa _exchangeRates como NULL
BitcoinExchange::BitcoinExchange(void) : _exchangeRates(NULL) {}

// Construtor de cópia: inicializa _exchangeRates com uma nova cópia do map de other
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _exchangeRates(new std::map<std::string, double>(*other._exchangeRates)) {}

// Construtor com filename: inicializa _exchangeRates com um novo map e lê os dados do arquivo
BitcoinExchange::BitcoinExchange(const std::string& filename)
	: _exchangeRates(new std::map<std::string, double>()) {
	readFile(filename.c_str(), true);
}

// Destrutor: deleta _exchangeRates
BitcoinExchange::~BitcoinExchange(void) {
	delete _exchangeRates;
}

// Operador de atribuição: copia os dados de other para o objeto atual
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {  // Verifica se não está atribuindo para si mesmo
		delete _exchangeRates;  // Deleta o map existente
		_exchangeRates = new std::map<std::string, double>(*other._exchangeRates);  // Cria um novo map copiando o de other
	}
	return (*this);  // Retorna a referência para o objeto atual
}

// Obtém a taxa de câmbio para uma data específica
double BitcoinExchange::getExchangeRate(const std::string& date) const {
	if (!_exchangeRates || _exchangeRates->empty()) {  // Verifica se _exchangeRates é nulo ou está vazio
		throw std::exception();  // Lança uma exceção
	}

	// Encontra a primeira data não menor que a data fornecida
	std::map<std::string, double>::const_iterator it = _exchangeRates->lower_bound(date);

	if (it == _exchangeRates->end()) {  // Se a data fornecida é maior que todas as datas no map
		return (--it)->second;  // Retorna a última taxa de câmbio no map
	}

	if (it->first == date) {  // Se a data encontrada é exatamente a data fornecida
		return it->second;  // Retorna a taxa de câmbio correspondente
	}

	if (it == _exchangeRates->begin()) {  // Se a data fornecida é menor que todas as datas no map
		return it->second;  // Retorna a primeira taxa de câmbio no map
	}

	return (--it)->second;  // Retorna a taxa de câmbio da data anterior à data fornecida
}

// Define as taxas de câmbio com um novo map
void BitcoinExchange::setExchangeRates(std::map<std::string, double>& newExchangeRates) {
	delete _exchangeRates;  // Deleta o map existente
	_exchangeRates = new std::map<std::string, double>(newExchangeRates);  // Cria um novo map com os novos dados
}

// Converte uma string para double e valida
double BitcoinExchange::parseDouble(const std::string& numberString) {
	std::stringstream stringStream(numberString);  // Cria um stringstream com a string fornecida
	double parsedValue;

	stringStream >> parsedValue;  // Tenta converter a string para double

	if (stringStream.fail() || !stringStream.eof()) {  // Verifica se a conversão falhou ou se há caracteres não processados
		throw std::domain_error("bad input => " + numberString);  // Lança uma exceção com uma mensagem de erro
	}

	if (parsedValue < 0) {  // Verifica se o valor convertido é negativo
		throw std::domain_error("not a positive number.");  // Lança uma exceção
	}

	return (parsedValue);  // Retorna o valor convertido
}

// Valida e analisa uma string de data
std::string BitcoinExchange::parseAndValidateDate(const std::string& dateString) {
	std::stringstream ss(dateString);  // Cria um stringstream com a string fornecida
	int year;
	int month;
	int day;
	char delimiter1, delimiter2;

	ss >> year >> delimiter1 >> month >> delimiter2 >> day;  // Tenta extrair ano, delimitador, mês, delimitador e dia
	if (ss.fail() || !ss.eof() || delimiter1 != '-' || delimiter2 != '-' || !isDateValid(dateString)) {
		// Verifica se a extração falhou, se há caracteres não processados,
		// se os delimitadores estão corretos e se a data é válida
		throw std::domain_error("bad input => " + dateString);  // Lança uma exceção com uma mensagem de erro
	}

	return (dateString);  // Retorna a data validada
}

// Analisa e valida uma linha de entrada
std::pair<std::string, double> BitcoinExchange::parseAndValidateInput(const std::string& inputLine) {
	std::string date;
	std::string validValue;
	double bitcoinValue;

	if (inputLine.length() < 14) {  // Verifica se a linha de entrada é muito curta
		throw std::domain_error("bad input => " + inputLine);  // Lança uma exceção com uma mensagem de erro
	}
	
	date = parseAndValidateDate(inputLine.substr(0, inputLine.find('|') - 1));  // Extrai e valida a data
	bitcoinValue = parseDouble(inputLine.substr(date.size() + 2));  // Extrai e converte o valor de bitcoin
	validValue = inputLine.substr(date.size() + 2);  // Extrai o valor de bitcoin como string

	if (validValue.find('-') != std::string::npos) {  // Verifica se o valor contém um sinal de negativo
		throw std::domain_error("not a positive number.");  // Lança uma exceção
	}

	if (bitcoinValue > 1000) {  // Verifica se o valor de bitcoin é muito grande
		throw std::domain_error("too large a number.");  // Lança uma exceção
	}

	return std::pair<std::string, double>(date, bitcoinValue);  // Retorna a data e o valor de bitcoin como um par
}

// Analisa e valida uma linha de entrada CSV
std::pair<std::string, double> BitcoinExchange::parseAndValidateCsv(const std::string& inputLine) {
	double bitcoinValue;
	std::string dateString;

	if (inputLine.size() < 12 || inputLine[10] != ',') {  // Verifica se a linha é muito curta ou se o formato está incorreto
		throw std::domain_error("bad input => " + inputLine);  // Lança uma exceção com uma mensagem de erro
	}

	dateString = parseAndValidateDate(inputLine.substr(0, inputLine.find(',')));  // Extrai e valida a data
	bitcoinValue = parseDouble(inputLine.substr(dateString.size() + 1));  // Extrai e converte o valor de bitcoin

	return std::pair<std::string, double>(dateString, bitcoinValue);  // Retorna a data e o valor de bitcoin como um par
}

// Verifica se a data é válida e não é futura
bool BitcoinExchange::isDateValid(const std::string& dateString) {
	std::stringstream ss(dateString);  // Cria um stringstream com a string fornecida
	std::string yearString;
	std::string monthString;
	std::string dayString;
	char delimiter1;
	char delimiter2;
	int year;
	int month; 
	int day;
	size_t pos1;
	size_t pos2;
	
	// Extrai a parte do ano da string de data
	pos1 = dateString.find('-');
	yearString = dateString.substr(0, pos1);
	// Extrai a parte do mês da string de data
	pos2 = dateString.find('-', pos1 + 1);
	monthString = dateString.substr((pos1 + 1), pos2 - pos1 - 1);
	// Extrai a parte do dia da string de data
	dayString = dateString.substr((pos2 + 1));

	// Tenta extrair o ano, delimitador, mês, delimitador e dia da string
	ss >> year >> delimiter1 >> month >> delimiter2 >> day;

	// Verifica se o ano, mês e dia estão dentro dos limites válidos e se os delimitadores estão corretos
	if (year < 0 || yearString.size() != 4 || 
		month < 1 || month > 12 || monthString.size() != 2 ||
		day < 1 || day > 31 || dayString.size() != 2) {
		return false;  // Retorna false se qualquer validação falhar
	}

	// Define a quantidade de dias em cada mês
	static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days = daysInMonth[month - 1];

	// Verifica se é um ano bissexto para fevereiro
	if (month == 2) {
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
			days = 29;
		}
	}
	
	// Retorna true se o dia está dentro do limite para o mês, caso contrário false
	return (day <= days);
}

// Lê um arquivo e processa as linhas
void BitcoinExchange::readFile(const char* filename, bool isCsv) {
	std::ifstream file(filename);  // Abre o arquivo
	std::string line;
	bool hasContent;

	if (!file || file.fail()) {  // Verifica se o arquivo foi aberto corretamente
		throw std::runtime_error(std::string("Error: could not open database file: ") + filename);  // Lança uma exceção com uma mensagem de erro
	}

	hasContent = false;  // Inicializa a flag de conteúdo como false

	if (!std::getline(file, line)) {  // Verifica se o arquivo está vazio
		throw std::runtime_error("The file is empty.");  // Lança uma exceção
	}

	while (std::getline(file, line)) {  // Lê cada linha do arquivo
		hasContent = true;  // Marca que o arquivo tem conteúdo
		try {
			processLine(line, isCsv);  // Processa a linha atual
		} catch (std::domain_error& e) {
			std::cerr << "Error: " << e.what() << std::endl;  // Imprime mensagens de erro de domínio
		} catch (std::exception& e) {
			std::cerr << "Error: bad input => " << line << std::endl;  // Imprime mensagens de erro genéricas
		}
	}

	if (isCsv && !_exchangeRates->empty() && !hasContent) {  // Verifica se o arquivo CSV está vazio após o processamento
		throw std::runtime_error("The database is empty after processing the file.");  // Lança uma exceção
	}
}

// Processa uma linha de entrada
void BitcoinExchange::processLine(const std::string& line, bool isCsv) {
	double rate;

	// Analisa e valida a linha de entrada
	std::pair<std::string, double> parsedLine = isCsv ? parseAndValidateCsv(line) : parseAndValidateInput(line);
	
	if (isCsv) {
		_exchangeRates->insert(parsedLine);  // Insere a data e a taxa de câmbio no map
	} else {
		rate = getExchangeRate(parsedLine.first);  // Obtém a taxa de câmbio para a data fornecida
		std::cout << parsedLine.first << " => " << parsedLine.second << " = " << parsedLine.second * rate << std::endl;  // Imprime a data, valor de bitcoin e a conversão
	}
}

// Processa o arquivo de entrada
void BitcoinExchange::processInput(const char* file) {
	if (!_exchangeRates || _exchangeRates->empty()) {  // Verifica se _exchangeRates é nulo ou está vazio
		throw std::exception();  // Lança uma exceção
	}
	readFile(file, false);  // Lê e processa o arquivo de entrada
}

// Função principal para executar a troca de bitcoin
bool BitcoinExchange::runBitcoinExchange(char* argv[]) {
	try {
		BitcoinExchange exchange("data.csv");  // Cria um objeto BitcoinExchange e lê os dados do arquivo "data.csv"
		exchange.processInput(argv[1]);  // Processa o arquivo de entrada fornecido pelo usuário
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;  // Imprime mensagens de erro
		return false;  // Retorna false em caso de erro
	}
	return true;  // Retorna true se tudo for bem-sucedido
}
