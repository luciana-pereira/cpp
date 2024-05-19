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

// Construtor padr�o
RPN::RPN(void) {}

// Construtor de c�pia
RPN::RPN(RPN const &others) {
    *this = others;
}

// Destrutor
RPN::~RPN(void) {}

// Operador de atribui��o
RPN& RPN::operator=(RPN const &others) {
    (void)others;
    return (*this);
}

// M�todo para verificar se um caractere � um sinal v�lido (+, -) seguido por d�gitos
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

// M�todo para verificar se uma string representa um n�mero inteiro v�lido
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

// M�todo para verificar se uma string representa um n�mero de ponto flutuante v�lido
bool RPN::isValidFloat(const std::string str) {
    size_t index;
    int numDecimalPoints;

    // Verifica se a string � um n�mero inteiro v�lido
    if (isValidInteger(str))
        return(true);

    // Verifica se a string come�a com um sinal v�lido seguido por d�gitos
    if (!checkSignAndDigits(str, index))
        return(false);

    // Reinicializa o �ndice para 0
    index = 0;
    numDecimalPoints = 0;   
    while (index <  str.length()) {
        // Verifica se h� um ponto decimal na string
        if (str[index] == '.' ){
            numDecimalPoints++;
            index++;
        }
        // Verifica se todos os caracteres s�o d�gitos
        if (!std::isdigit(str[index])) {
            return (false);
        }
        index++;
    }

    // Verifica se h� mais de um ponto decimal na string
    if (numDecimalPoints > 1) {
        return (false);
    }

    return(true);
}

// M�todo para realizar uma opera��o espec�fica com os dois operandos fornecidos e o operador dado
double RPN::performOperation(double operand1, double operand2, const std::string& operatorToken) {
    if (operatorToken == "/") {
        // Verifica se ocorre divis�o por zero
        if (operand2 == 0.0) {
            throw std::runtime_error("Division by zero.");
        }

        return (operand1 / operand2);
    }

    // Realiza a opera��o com base no operador
    if (operatorToken == "+") {
        return (operand1 + operand2);
    } else if (operatorToken == "-") {
        return (operand1 - operand2);
    } else if (operatorToken == "*") {
        return (operand1 * operand2);
    }
    // Lan�a uma exce��o se o operador n�o for v�lido
    throw std::runtime_error("Invalid operator.");
}

// M�todo para empilhar n�meros na pilha de opera��es
void RPN::pushNumbers(std::stack<double>& stack, const std::string& token) {
    double number;

    // Verifica se o token � um n�mero de ponto flutuante v�lido
    if (!isValidFloat(token)) {
        throw std::runtime_error("Invalid token encountered: '" + token + "'.");
    }
    // Converte o token em um n�mero de ponto flutuante e o empilha na pilha
    number = atof(token.c_str());
    stack.push(number);
}

// M�todo para realizar opera��es com base no operador atual e os dois operandos do topo da pilha
double RPN::performOperations(std::stack<double>& stack, const std::string& token) {
    double operand1;
    double operand2;
    
    // Verifica se h� pelo menos dois operandos na pilha
    if (stack.size() < 2) {
        throw std::runtime_error("Invalid RPN expression");
    }
    // Remove os dois operandos do topo da pilha
    operand2 = stack.top();
    stack.pop();
    operand1 = stack.top();
    stack.pop();
    // Realiza a opera��o com os operandos e o operador atual e retorna o resultado
    return (performOperation(operand1, operand2, token));
}

// M�todo para avaliar uma express�o RPN e retornar o resultado
double RPN::evaluate(const std::string& expression) {
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;

    // Percorre a express�o token por token
    while (iss >> token) {
        // Se o token for um operador, realiza as opera��es correspondentes
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            double result = performOperations(stack, token);
            stack.push(result);
        } else {
            // Se o token for um n�mero, o empilha na pilha
            pushNumbers(stack, token);
        }
    }

    // Verifica se h� exatamente um n�mero na pilha ap�s a avalia��o da express�o
    if (stack.size() != 1) {
        throw std::runtime_error("Invalid expression");
    }

    // Retorna o n�mero resultante
    return (stack.top());
}

