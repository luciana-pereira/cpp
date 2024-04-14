/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 01:29:46 by lucperei          #+#    #+#             */
/*   Updated: 2024/04/15 01:34:16 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

// construtor e do destruidor
Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I really do!" << std::endl;
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started ";
	std::cout << "working here since last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Harl::complain(std::string level)
{
	// Converte para inteiro
	int hash = 0;
	// Constantes para os valores de offset e de divisão na hash
	const int hash_offset = 696;
	const int hash_divider = 25;
	// Constante para o fator de peso do caractere na hash
	const int weight_factor = 4;

	// Cálculo da hash
	for (size_t index = 0; index < 4; ++index)
		// Adiciona ao hash o valor ASCII do caractere multiplicado pelo fator 
		// de peso correspondente
		hash += level[index] * (weight_factor - index);
	
	// Determina o nível com base na hash calculada e no enum no .hpp
	switch ((hash - hash_offset) / hash_divider)
	{
		case Harl::DEBUG:
			debug();
			info();
			warning();
			error();
			break ;
		case Harl::INFO:
			info();
			warning();
			error();
			break ;
		case Harl::WARNING:
			warning();
			error();
			break ;
		case Harl::ERROR:
			error();
		 	break ;
	}
}
