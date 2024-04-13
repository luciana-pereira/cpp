/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:40:06 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/07 17:11:38 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

// Inicializa o contador de contatos _contacts_count como zero.
PhoneBook::PhoneBook(void) : _contacts_count(0){};

// Método permite adicionar um novo contato à lista
void	PhoneBook::addContact(void)
{
	if (PhoneBook::_contacts_count < MAX_CONTACT) // Se huver espaço disponivel na lista ele chama o metodo para preencher os dados do novo contato.
	{
		_contacts[PhoneBook::_contacts_count++].getContactData();
		std::cout << CONTACT_ADDED << std::endl;
	}
	else //  Caso contrário, imprime uma mensagem informando que a lista de contatos está cheia.
		std::cout << FULL_SCHEDULE << std::endl;
}

// Método permite procurar um contato na lista
void	PhoneBook::searchContact(void)
{
	if (PhoneBook::_contacts_count == 0) // Se não houver contato na lista, imprime mensagem informando que a lista está vazia
	{
		std::cout << EMPTY_SCHEDULE << std::endl;
		return ;
	}
	// Caso contrario chama os métodos abaixo para para exibir o cabeçalho da lista de contatos 
	// e solicitar um índice de contato válido para visualização.
	_displayHeader();
	_getValidIndex();
}

// Método formata os dados do contato para exibição
std::string	PhoneBook::_displayFormattedData(const std::string& data)
{
	std::stringstream formatted;
	// Se o comprimento do dado for maior que 10 caracteres, 
	// ele trunca o dado para 9 caracteres e adiciona reticências
	if (data.length() > 10)
		formatted << data.substr(0, 9) + "."; // A substr extrai uma parte de uma string com o index e tamanho como parametro
	else // Caso contrário, retorna o dado sem alterações.
		formatted << data;
	return (formatted.str());
}

// Método exibe o cabeçalho da lista de contatos, incluindo os nomes dos campos 
// e os dados de cada contato na lista.
void	PhoneBook::_displayHeader(void)
{
	std::cout.setf(std::ios_base::right); // O setf() é um método da classe std::ios_base que configura a flag 
	// em vários aspectos da formatação de saída, como alinhamento a direita
	std::cout << std::setw(10) << "index" << "|"; // O setw definir a largura do campo
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < PhoneBook::_contacts_count; i++)
	{
		std::cout << std::setw(10) << (i + 1) << "|";
		std::cout << std::setw(10)
			<< _displayFormattedData(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10)
			<< _displayFormattedData(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10)
			<< _displayFormattedData(_contacts[i].getNickname()) << std::endl;
	}
}

// Método exibe os detalhes de um contato específico com base no índice fornecido
int	PhoneBook::_displayContact(int index)
{
	// Percorre a lista de contatos e compara os índices até encontrar o contato correspondente.
	for (int contact_index = 0; contact_index < PhoneBook::_contacts_count; contact_index++)
	{
		if ((contact_index) == index) // Se encontrar, imprime os detalhes do contato
		{
			std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
			std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
			std::cout << "Nick name: " << _contacts[index].getNickname() << std::endl;
			std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
			std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
			return (true);
		}
	}
	//  Se o índice fornecido for inválido, imprime uma mensagem informando que o índice é inválido.
	std::cout << INVALID_INDEX << std::endl;
	return (false);
}


// Os métodos abaixo, _getInputIndex() e _isValidIndex() são usados para obter e validar a entrada do usuário
// para o índice do contato a ser exibido.
std::string	PhoneBook::_getInputIndex(void)
{
	std::string	index;

	if (!std::cin.eof()) // eof, acessa o estado final do arquivo, aqui no caso esta verificando se atingiu o final do arquiv
	{
		std::cout << INPUT_INDEX << std::endl;
		std::getline(std::cin, index);
	}
	return (index);
}

bool	PhoneBook::_isValidIndex(std::string& index)
{
	if (index.length())
	{
		if (index.length() > 1)
		{
			std::cout << INVALID_INDEX << std::endl;
			return (false);
		}
		return (true);
	}
	return (false);
}

// Método solicita repetidamente ao usuário um índice de contato válido até que seja fornecido um índice válido.
void	PhoneBook::_getValidIndex(void)
{
	std::string	index;

	while (true)
	{
		index = _getInputIndex();
		if (std::cin.eof())  // Se atingiu o final do arquivo
		{
			std::cout << std::endl;
			return ;
		}
		if (_isValidIndex(index)) // Fornecido um índice válido
		{
			if (_displayContact(index[0] - '1')) // O método _displayContact() exibira os detalhes do contato correspondente.
				return ;
		}
	}
}
