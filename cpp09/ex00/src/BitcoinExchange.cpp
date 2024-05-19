/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:12:17 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/18 07:28:43 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/BitcoinExchange.hpp"

// Construtor padrão que inicializa _exchangeRates como NULL.
BitcoinExchange::BitcoinExchange(void) : _exchangeRates(NULL) {}

// Construtor de cópia que inicializa _exchangeRates como uma nova cópia do mapa de taxas de câmbio do objeto original.
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
    : _exchangeRates(new std::map<std::string, double>(*other._exchangeRates)) {}

// Construtor que inicializa _exchangeRates e chama readFile para processar um arquivo CSV.
BitcoinExchange::BitcoinExchange(const std::string& filename) 
    : _exchangeRates(new std::map<std::string, double>()) {
    readFile(filename.c_str(), true);  // Chama a função para ler o arquivo.
}

// Destrutor que libera a memória alocada para _exchangeRates.
BitcoinExchange::~BitcoinExchange(void) {
    delete _exchangeRates;
}

// Sobrecarga do operador de atribuição que copia as taxas de câmbio de um outro objeto BitcoinExchange.
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  // verifica se o objeto ao qual o operador de atribuição está sendo aplicado não é o mesmo objeto que 
  // está sendo passado como argumento para o operador de atribuição
    if (this != &other) {
        delete _exchangeRates;  // Libera a memória atual.
        _exchangeRates = new std::map<std::string, double>(*other._exchangeRates);  // Copia o mapa.
    }
    return *this;
}

// Obtém a taxa de câmbio para uma data específica.
double BitcoinExchange::getExchangeRate(const std::string& date) const {
    if (!_exchangeRates || _exchangeRates->empty()) {
        throw std::exception();  // Lança exceção se _exchangeRates estiver vazio ou não inicializado.
    }
  
  // lower_bound procura pelo primeiro elemento cuja chave "date" é maior ou igual
    std::map<std::string, double>::const_iterator it = _exchangeRates->lower_bound(date);

    if (it == _exchangeRates->end()) {
        return (--it)->second;  // Retorna a última taxa se a data for maior que todas as datas no mapa.
    }

    if (it->first == date) {
        return it->second;  // Retorna a taxa exata se a data coincidir.
    }

    if (it == _exchangeRates->begin()) {
        throw std::exception();  // Lança exceção se a data for anterior a todas as datas no mapa.
    }

    return (--it)->second;  // Retorna a taxa mais próxima anterior à data fornecida.
}

// Define novas taxas de câmbio substituindo o mapa existente.
void BitcoinExchange::setExchangeRates(std::map<std::string, double>& newExchangeRates) {
    delete _exchangeRates;
    _exchangeRates = new std::map<std::string, double>(newExchangeRates);
}

// Analisa uma string e a converte em um double, garantindo que é um número válido e positivo.
double BitcoinExchange::parseDouble(const std::string& numberString) {
      // Cria um objeto stringstream inicializado com numberString
    std::stringstream stringStream(numberString);
    double parsedValue;
// Tenta ler um valor double do fluxo
    stringStream >> parsedValue;
  
    // Verifica se a leitura falhou ou se restaram caracteres não processados
    if (stringStream.fail() || !stringStream.eof())
        throw std::domain_error("bad input => " + numberString);
  
    // Verifica se o valor lido é negativo
    if (parsedValue < 0)
        throw std::domain_error("not a positive number.");
    // Retorna o valor double lido
    return parsedValue;
}

// Valida e converte uma string de data no formato YYYY-MM-DD.
std::string BitcoinExchange::parseAndValidateDate(const std::string& dateString) {
    std::tm timeStruct; // Criando uma instancia para armazenar informações de data

  // Verifica o formato da data se e valida
    if (!strptime(dateString.c_str(), "%Y-%m-%d", &timeStruct) || !isDateValid(timeStruct))
        throw std::domain_error("bad input => " + dateString);

    return (dateString); // retorna adata se estiver ok.
}

// Analisa e valida uma linha de entrada, retornando uma data e um valor de bitcoin.
std::pair<std::string, double> BitcoinExchange::parseAndValidateInput(const std::string& inputLine) {
    // Extrai data e valor
    std::string date = parseAndValidateDate(inputLine.substr(0, 10));
    double bitcoinValue = parseDouble(inputLine.substr(13));

    if (bitcoinValue > 1000)
        throw std::domain_error("too large a number.");

    return std::pair<std::string, double>(date, bitcoinValue);
}

// Analisa e valida uma linha de um arquivo CSV do data.csv, retornando uma data e um valor de bitcoin.
std::pair<std::string, double> BitcoinExchange::parseAndValidateCsv(const std::string& inputLine) {
    double bitcoinValue;
    std::string dateString;
    // Verificar formatação
    if (inputLine.size() < 12 || inputLine[10] != ',') {
        throw std::domain_error("bad input => " + inputLine);
    }
    // Extrai o valor e data do arquivo
    bitcoinValue = parseDouble(inputLine.substr(11));
    dateString = parseAndValidateDate(inputLine.substr(0, 10));

    return std::pair<std::string, double>(dateString, bitcoinValue);
}

// Verifica se uma data é válida considerando anos bissextos.
bool BitcoinExchange::isDateValid(const std::tm& timeStruct) {
   // Quatidade dedias que contem cada mês
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int days = daysInMonth[timeStruct.tm_mon]; // Obtém o número de dias no mês específico.

    if (timeStruct.tm_mon == 1) {  // Verifica se o mês é fevereiro (índice 1).
        int year = 1900 + timeStruct.tm_year;
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            days = 29; // Atualiza para 29 dias se for um ano bissexto.
    }
    return (timeStruct.tm_mday <= days); // Verifica se o dia está dentro do limite de dias do mês.
}

// Lê um arquivo linha por linha e processa cada linha como CSV ou entrada padrão.
void BitcoinExchange::readFile(const char* filename, bool isCsv) {
    std::ifstream file(filename);
    
    if (!file || file.fail()) {
        throw std::runtime_error(std::string("Error: could not open database file: ") + filename);
    }

    std::string line;
    bool hasContent = false;

    if (!std::getline(file, line)) {
        throw std::runtime_error("The file is empty.");
    }

    while (std::getline(file, line)) {
        hasContent = true;
        try {
            processLine(line, isCsv);  // Processa cada linha.
        } catch (std::domain_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    if (isCsv && _exchangeRates->empty() && !hasContent) {
        throw std::runtime_error("The database is empty after processing the file.");
    }
}

// Processa uma linha específica, analisando e inserindo os valores apropriados.
void BitcoinExchange::processLine(const std::string& line, bool isCsv) {
    std::pair<std::string, double> parsedLine = isCsv ? parseAndValidateCsv(line) : parseAndValidateInput(line);
    
    if (isCsv) {
        _exchangeRates->insert(parsedLine);
    } else {
        double rate = getExchangeRate(parsedLine.first);
        std::cout << parsedLine.first << " => " << parsedLine.second << " = " << parsedLine.second * rate << std::endl;
    }
}

// Processa um arquivo de entrada que contém dados para calcular os valores em bitcoin.
void BitcoinExchange::processInput(const char* file) {
    if (!_exchangeRates || _exchangeRates->empty()) {
        throw std::exception();
    }
    readFile(file, false);
}

// Função principal que executa a lógica da troca de bitcoin, lidando com exceções.
bool BitcoinExchange::runBitcoinExchange(char* argv[]) {
    try {
        BitcoinExchange exchange("data.csv");  // Inicializa com um arquivo CSV de dados.
        exchange.processInput(argv[1]);  // Processa o arquivo de entrada fornecido.
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    return true;
}
