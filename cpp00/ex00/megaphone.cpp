/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:12:38 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/06 19:12:40 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // Fornece as funcionalidades de entrada e saída padrão em C++.

int main(int argc, char **argv)
{
	if (argc < 2) // Verifica se há pelo menos dois argumentos (o primeiro é o nome do programa).
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; ++i) // Para cada argumento (começando do segundo, pois o primeiro é o nome do programa), percorre cada caractere.
		{
			for (int j = 0; argv[i][j] != '\0'; ++j)
				std::cout << (char)std::toupper(argv[i][j]); // Converte cada caractere para maiúsculo usando std::toupper e o imprime.
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}
