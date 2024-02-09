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

PhoneBook::PhoneBook(void) : _contacts_count(0){};

void	PhoneBook::addContact(void)
{
	if (PhoneBook::_contacts_count < MAX_CONTACT)
	{
		_contacts[PhoneBook::_contacts_count++].getContactData();
		std::cout << CONTACT_ADDED << std::endl;
	}
	else
		std::cout << FULL_SCHEDULE << std::endl;
}

void	PhoneBook::searchContact(void)
{
	if (PhoneBook::_contacts_count == 0)
	{
		std::cout << EMPTY_SCHEDULE << std::endl;
		return ;
	}
	_displayHeader();
	_getValidIndex();
}

std::string	PhoneBook::_displayFormattedData(const std::string& data)
{
	std::stringstream formatted;

	if (data.length() > 10)
		formatted << data.substr(0, 9) + ".";
	else
		formatted << data;
	return (formatted.str());
}

void	PhoneBook::_displayHeader(void)
{
	std::cout.setf(std::ios_base::right);
	std::cout << std::setw(10) << "index" << "|";
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

int	PhoneBook::_displayContact(int index)
{
	for (int contact_index = 0; contact_index < PhoneBook::_contacts_count; contact_index++)
	{
		if ((contact_index) == index)
		{
			std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
			std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
			std::cout << "Nick name: " << _contacts[index].getNickname() << std::endl;
			std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
			std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
			return (true);
		}
	}
	std::cout << INVALID_INDEX << std::endl;
	return (false);
}

std::string	PhoneBook::_getInputIndex(void)
{
	std::string	index;

	if (!std::cin.eof())
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

void	PhoneBook::_getValidIndex(void)
{
	std::string	index;

	while (true)
	{
		index = _getInputIndex();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ;
		}
		if (_isValidIndex(index))
		{
			if (_displayContact(index[0] - '1'))
				return ;
		}
	}
}
