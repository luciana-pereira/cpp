/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 02:02:37 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/07 18:23:39 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

// O contrutor abaixo inicializa  os membros de dados com string vazia.
Contact::Contact(void)
	: first_name(""),
	last_name(""),
	nickname(""),
	phone_number(""),
	darkest_secret("")
{};

// Abaixo temos os métodos de acesso público que retornam os valores dos membros de dados correspondente.
std::string	Contact::getFirstName(void)
{
	return (this->first_name);
}

std::string	Contact::getLastName(void)
{
	return (this->last_name);
}

std::string	Contact::getNickname(void)
{
	return (this->nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->phone_number);
}

std::string	Contact::getDarkestSecret(void)
{
	return (this->darkest_secret);
}

// Abaixo temos os metodos privados para limpeza de dados:

// Método pa remover espaços consecutivos ou espaços no início e no final da string, 
// intera sobre a string com for ate que não aja mais caracteres a serem removidos, 
// ao logo de seu comprimento(size), utilizando da função erase() para remover o caracter 
// de espaço, nela passamos o indice onde caracter sera removido e a quantidade no caso 1.
void	Contact::_removeConsecutiveSpaces(std::string& data)
{
	int	size;

	size = data.length();
	for (int i = 0; i < size; i++)
	{
		if ((data[i] == ' ' || data[i] == '\t') &&
			(data[i + 1] == ' ' || data[i + 1] == '\t'))
		{
			data.erase(i, 1);
			size = data.length();
			i = 0;
		}
	}
}

// Método para remover espaços no início e no final de uma string.
void	Contact::_removeOuterSpaces(std::string& data)
{
	int	size;

	size = data.length();
	while (size > 0 && (data[size - 1] == ' ' || data[size - 1] == '\t'))
	{
		data.erase(size - 1, 1);
		size = data.length();
	}
	while (size > 0 && (data[0] == ' ' || data[0] == '\t'))
	{
		data.erase(0, 1);
		size = data.length();
	}
}

// Método aplica as funções de limpeza de dados para remover espaços desnecessários.
void	Contact::_cleanContactData(std::string& data)
{
	int	size;

	size = data.length();
	if (size)
	{
		_removeConsecutiveSpaces(data);
		_removeOuterSpaces(data);
	}
}

// Abaixo temos os metodos privados para validação de dados

// Método para verifica se todos os caracteres de uma string de número de telefone são dígitos ou o caractere '+'.
bool	Contact::_validatePhoneCharacters(std::string& phone_number)
{
	for (std::size_t index = 0; index < phone_number.length(); ++index)
	{
		if (!isdigit(phone_number[index]) && phone_number[index] != '+')
		{
			std::cout << INVALID_CARACTER_PHONE << std::endl;
			phone_number.clear();
			return (false);
		}
	}
	return (true);
}

// Método para verifica se o comprimento de uma string de número de telefone é válido.
void	Contact::_validatePhoneLength(std::string& phone_number)
{
	if ((phone_number[0] == '+' && phone_number.length() != 14) ||
		(phone_number[0] != '+' && (phone_number.length() > 13 ||
									phone_number.length() < 8)))
	{
		std::cout << INVALID_PHONE << std::endl;
		phone_number.clear();
	}
}

// Método aplica as funções de validação de número de telefone.
void	Contact::_verifyPhoneNumber(std::string& phone_number)
{
	_cleanContactData(phone_number);
	if (_validatePhoneCharacters(phone_number))
	{
		_validatePhoneLength(phone_number);
	}
}

// Método para verifica se todos os caracteres de uma string são imprimíveis.
void	Contact::_verifyCharacters(std::string& contact_data)
{
	for (std::size_t index = 0; index < contact_data.length(); ++index)
	{
		if (contact_data[index] < ' ' || contact_data[index] > '~')
		{
			std::cout << INVALID_CARACTER << std::endl;
			contact_data.clear();
			return ;
		}
	}
}

// Método solicita a entrada do usuário para um campo específico do contato, limpa e valida os dados de entrada.
void	Contact::_getInput(const std::string& field, std::string& data, int index)
{
	while (true)
	{
		std::cout << field << ": ";
		std::getline(std::cin, data);
		if (!data.empty())
		{
			_cleanContactData(data);
			if (index == 3)
				_verifyPhoneNumber(data);
			else
				_verifyCharacters(data);
			if (!data.empty())
				break ;
		}
		else
		{
			std::cout << VALID_INPUT << field << "." << std::endl;
		}
	}
}

// Método atribui os dados de contato aos membros de dados correspondentes.
void	Contact::_assignData(const std::string contact_data[])
{
	first_name = contact_data[0];
	last_name = contact_data[1];
	nickname = contact_data[2];
	phone_number = contact_data[3];
	darkest_secret = contact_data[4];
}

// Método solicita a entrada de dados para cada campo do contato (nome, sobrenome, apelido, 
// número de telefone e segredo mais obscuro) e os atribui aos membros de dados correspondentes.
void	Contact::getContactData(void)
{
	std::string fields[5] = {
		"First name",
		"Last name",
		"Nickname",
		"Phone number",
		"Darkest secret"
	};
	std::string contact_data[5];

	for (int index = 0; index < 5; ++index)
	{
		_getInput(fields[index], contact_data[index], index);
	}
	_assignData(contact_data);
}
