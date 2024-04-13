/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:56:34 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/07 16:51:10 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	while (1) // Loop infinito, ou seja, enquanto for verdadeiro ou não entra na condição de saída para ser interrompido.
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
		std::getline(std::cin, command); // Lê a entrada do usuário com o std::cin e std::getline lê uma linha inteira de entrada e armazena em command.
		if(command == "EXIT" || std::cin.eof()) // Se o comando for "EXIT" ou se for o final do arquivo (std::cin.eof()) exibe a mensagem abaixo.
		{
			std::cout << "Exiting the program. Contacts will be lost forever!" << std::endl;
			break ;
		}
		else if (command == "ADD")
			phonebook.addContact(); // O método addContact() do objeto phonebook é chamado para adicionar um novo contato.
		else if (command == "SEARCH")
			phonebook.searchContact(); // O método searchContact() do objeto phonebook é chamado para pesquisar um contato existente.
		else // Se o comando de entrada não for reconhecido, o programa exibe uma mensagem de erro.
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return (0);
}
