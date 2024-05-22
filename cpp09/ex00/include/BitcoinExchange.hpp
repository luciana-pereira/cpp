/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:13:35 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/22 19:26:25 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <exception>   // Inclui a biblioteca para manipulação de exceções
#include <iostream>    // Inclui a biblioteca para operações de entrada e saída
#include <fstream>     // Inclui a biblioteca para manipulação de arquivos
#include <sstream>     // Inclui a biblioteca para manipulação de string streams
#include <string>      // Inclui a biblioteca para manipulação de strings
#include <cstring>     // Inclui a biblioteca para manipulação de C-strings
#include <ctime>       // Inclui a biblioteca para manipulação de tempo e data
#include <map>         // Inclui a biblioteca para a estrutura de dados map

class BitcoinExchange {
public:
    // Construtor padrão
    BitcoinExchange(void);

    // Construtor de cópia
    BitcoinExchange(const BitcoinExchange& other);

    // Construtor que aceita um nome de arquivo
    BitcoinExchange(const std::string& filename);

    // Destrutor
    ~BitcoinExchange(void);

    // Operador de atribuição de cópia
    BitcoinExchange& operator=(const BitcoinExchange& other);

    // Obtém a taxa de câmbio para uma data específica
    double getExchangeRate(const std::string& date) const;

    // Define novas taxas de câmbio
    void setExchangeRates(std::map<std::string, double>& newExchangeRates);

    // Executa o programa BitcoinExchange
    bool runBitcoinExchange(char* argv[]);

    // Processa o arquivo de entrada
    void processInput(const char* file);

private:
    // Converte uma string para um valor double, verificando erros
    double parseDouble(const std::string& numberString);

    // Valida e converte uma string de data
    std::string parseAndValidateDate(const std::string& dateString);

    // Valida e analisa uma linha de entrada
    std::pair<std::string, double> parseAndValidateInput(const std::string& inputLine);

    // Valida e analisa uma linha de CSV
    std::pair<std::string, double> parseAndValidateCsv(const std::string& inputLine);

    // Verifica se uma data é válida
    bool isDateValid(const std::tm& timeStruct);

    // Lê um arquivo e processa seu conteúdo
    void readFile(const char* filename, bool isCsv);

    // Processa uma linha do arquivo
    void processLine(const std::string& line, bool isCsv);

    // Ponteiro para um mapa de taxas de câmbio
    std::map<std::string, double>* _exchangeRates;
};

#endif
