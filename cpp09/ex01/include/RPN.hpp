/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:02:09 by user42            #+#    #+#             */
/*   Updated: 2024/05/19 16:17:21 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <cstdlib>

class RPN {
    public:
        RPN(void); // Construtor padrão
        ~RPN(void); // Destrutor
        RPN(RPN const &others); // Construtor de cópia
        RPN& operator=(RPN const &others); // Operador de atribuição

        // Método para avaliar uma expressão RPN e retornar o resultado
        double evaluate(const std::string& expression);

    private:
        // Método para verificar se um caractere é um sinal válido (+, -, *, /)
        bool checkSignAndDigits(const std::string& str, size_t& index);
        
        // Método para verificar se uma string representa um número inteiro válido
        bool isValidInteger(std::string str);
        
        // Método para verificar se uma string representa um número de ponto flutuante válido
        bool isValidFloat(std::string str);
        
        // Método para empilhar números na pilha de operações
        void pushNumbers(std::stack<double>& stack, const std::string& token);
        
        // Método para realizar operações com base no operador atual e os dois operandos do topo da pilha
        double performOperations(std::stack<double>& stack, const std::string& token);
        
        // Método para realizar uma operação específica com os dois operandos fornecidos e o operador dado
        double performOperation(double operand1, double operand2, const std::string& operatorToken);
};

#endif

