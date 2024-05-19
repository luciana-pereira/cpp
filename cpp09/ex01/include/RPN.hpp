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
        RPN(void); // Construtor padr�o
        ~RPN(void); // Destrutor
        RPN(RPN const &others); // Construtor de c�pia
        RPN& operator=(RPN const &others); // Operador de atribui��o

        // M�todo para avaliar uma express�o RPN e retornar o resultado
        double evaluate(const std::string& expression);

    private:
        // M�todo para verificar se um caractere � um sinal v�lido (+, -, *, /)
        bool checkSignAndDigits(const std::string& str, size_t& index);
        
        // M�todo para verificar se uma string representa um n�mero inteiro v�lido
        bool isValidInteger(std::string str);
        
        // M�todo para verificar se uma string representa um n�mero de ponto flutuante v�lido
        bool isValidFloat(std::string str);
        
        // M�todo para empilhar n�meros na pilha de opera��es
        void pushNumbers(std::stack<double>& stack, const std::string& token);
        
        // M�todo para realizar opera��es com base no operador atual e os dois operandos do topo da pilha
        double performOperations(std::stack<double>& stack, const std::string& token);
        
        // M�todo para realizar uma opera��o espec�fica com os dois operandos fornecidos e o operador dado
        double performOperation(double operand1, double operand2, const std::string& operatorToken);
};

#endif

