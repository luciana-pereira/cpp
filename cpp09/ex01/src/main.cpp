/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:08:39 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/19 15:38:48 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

// Fun��o principal
int main(int argc, char *argv[]) {
    // Verifica se o n�mero de argumentos fornecidos � v�lido
    if (argc != 2) {
        // Se o n�mero de argumentos n�o for v�lido, exibe uma mensagem de erro e retorna 1
        std::cerr << "Error: Invalid number of arguments supplied.\nUse: ./RPN \"<RPN expression>\"\nExample: ./RPN \"2 5 +\"" << std::endl;
        return (1);
    }

    try {
        // Cria uma inst�ncia da classe RPN
        RPN rpn;
        // Avalia a express�o RPN fornecida como argumento e armazena o resultado
        int result = rpn.evaluate(argv[1]);
        // Exibe o resultado
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        // Se ocorrer uma exce��o durante a avalia��o da express�o RPN, exibe uma mensagem de erro e retorna 1
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }

    // Retorna 0 para indicar que o programa foi executado com sucesso
    return (0);
}
