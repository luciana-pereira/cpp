/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:02:17 by user42            #+#    #+#             */
/*   Updated: 2024/05/19 16:49:43 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

// Construtor padrão
RPN::RPN(void) {}

// Construtor de cópia
RPN::RPN(RPN const &others) {
    *this = others;
}

// Destrutor
RPN::~RPN(void) {}

// Operador de atribuição
RPN& RPN::operator=(RPN const &others) {
    (void)others;
    return (*this);
}

// Método para verificar se um caractere é um sinal válido (+, -) seguido por dígitos
bool RPN::checkSignAndDigits(const std::string& str, size_t& index) {
    if (str.empty()) {
        return (false);
    }

    index = 0;
    if (str[index] == '+' || str[index] == '-') {
        index++;
        if (!std::isdigit(str[index])) {
            return (false);
        }
        index++;
    }
    return (true);
}

// Método para verificar se uma string representa um número inteiro válido
bool RPN::isValidInteger(const std::string str) {
    size_t index;

    index = 0;
    if (!checkSignAndDigits(str, index))
        return (false);

    while (index <  str.length()){
        if (!std::isdigit(str[index]))
            return (false);
        index++;
    }
    return (true);
}

// Método para verificar se uma string representa um número de ponto flutuante válido
bool RPN::isValidFloat(const std::string str) {
    size_t index;
    int numDecimalPoints;

    // Verifica se a string é um número inteiro válido
    if (isValidInteger(str))
        return(true);

    // Verifica se a string começa com um sinal válido seguido por dígitos
    if (!checkSignAndDigits(str, index))
        return(false);

    // Reinicializa o índice para 0
    index = 0;
    numDecimalPoints = 0;   
    while (index <  str.length()) {
        // Verifica se há um ponto decimal na string
        if (str[index] == '.' ){
            numDecimalPoints++;
            index++;
        }
        // Verifica se todos os caracteres são dígitos
        if (!std::isdigit(str[index])) {
            return (false);
        }
        index++;
    }

    // Verifica se há mais de um ponto decimal na string
    if (numDecimalPoints > 1) {
        return (false);
    }

    return(true);
}

// Método para realizar uma operação específica com os dois operandos fornecidos e o operador dado
double RPN::performOperation(double operand1, double operand2, const std::string& operatorToken) {
    if (operatorToken == "/") {
        // Verifica se ocorre divisão por zero
        if (operand2 == 0.0) {
            throw std::runtime_error("Division by zero.");
        }

        return (operand1 / operand2);
    }

    // Realiza a operação com base no operador
    if (operatorToken == "+") {
        return (operand1 + operand2);
    } else if (operatorToken == "-") {
        return (operand1 - operand2);
    } else if (operatorToken == "*") {
        return (operand1 * operand2);
    }
    // Lança uma exceção se o operador não for válido
    throw std::runtime_error("Invalid operator.");
}

// Método para empilhar números na pilha de operações
void RPN::pushNumbers(std::stack<double>& stack, const std::string& token) {
    double number;

    // Verifica se o token é um número de ponto flutuante válido
    if (!isValidFloat(token)) {
        throw std::runtime_error("Invalid token encountered: '" + token + "'.");
    }
    // Converte o token em um número de ponto flutuante e o empilha na pilha
    number = atof(token.c_str());
    stack.push(number);
}

// Método para realizar operações com base no operador atual e os dois operandos do topo da pilha
double RPN::performOperations(std::stack<double>& stack, const std::string& token) {
    double operand1;
    double operand2;
    
    // Verifica se há pelo menos dois operandos na pilha
    if (stack.size() < 2) {
        throw std::runtime_error("Invalid RPN expression");
    }
    // Remove os dois operandos do topo da pilha
    operand2 = stack.top();
    stack.pop();
    operand1 = stack.top();
    stack.pop();
    // Realiza a operação com os operandos e o operador atual e retorna o resultado
    return (performOperation(operand1, operand2, token));
}

// Método para avaliar uma expressão RPN e retornar o resultado
double RPN::evaluate(const std::string& expression) {
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;

    // Percorre a expressão token por token
    while (iss >> token) {
        // Se o token for um operador, realiza as operações correspondentes
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            double result = performOperations(stack, token);
            stack.push(result);
        } else {
            // Se o token for um número, o empilha na pilha
            pushNumbers(stack, token);
        }
    }

    // Verifica se há exatamente um número na pilha após a avaliação da expressão
    if (stack.size() != 1) {
        throw std::runtime_error("Invalid expression");
    }

    // Retorna o número resultante
    return (stack.top());
}

