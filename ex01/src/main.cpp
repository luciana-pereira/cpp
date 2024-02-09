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

	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
		std::getline(std::cin, command);
		if(command == "EXIT" || std::cin.eof())
		{
			std::cout << "Exiting the program. Contacts will be lost forever!" << std::endl;
			break ;
		}
		else if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return (0);
}
