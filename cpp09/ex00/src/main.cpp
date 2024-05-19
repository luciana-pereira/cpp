/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:16:02 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/18 22:49:29 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int	main(int argc, char *argv[]) {
    // Verifica se o número de argumentos passados é exatamente 2 (nome do programa + 1 argumento)
    if (argc != 2) {
        // Se não for, imprime uma mensagem de erro e retorna 1 indicando falha na execução
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }

    // Cria um objeto da classe BitcoinExchange
    BitcoinExchange exchange;

    // Tenta executar a função runBitcoinExchange passando os argumentos da linha de comando
    if (!exchange.runBitcoinExchange(argv)) {
        // Se runBitcoinExchange retornar false, retorna 1 indicando falha na execução
        return (1);
    }

    // Se tudo ocorrer bem, retorna 0 indicando sucesso na execução
    return (0);
}
