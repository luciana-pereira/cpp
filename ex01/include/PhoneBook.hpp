/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 00:30:17 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/07 16:52:50 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <limits>

# define MAX_CONTACT 8
# define CONTACT_ADDED "Contact added successfully!"
# define FULL_SCHEDULE "Phonebook is full. Cannot add more contacts."
# define EMPTY_SCHEDULE "Empty phone book!"
# define INVALID_INDEX "Error: Invalid index. Please try again."
# define INPUT_INDEX "Enter the index of the contact to display: "

class	PhoneBook
{
	public:
		PhoneBook(void);
		void		addContact(void);
		void		searchContact(void);
	private:
		Contact		_contacts[MAX_CONTACT];
		int			_contacts_count;
		void		_displayHeader(void);
		int			_displayContact(int index);
		void		_getValidIndex(void);
		bool		_isValidIndex(std::string& index);
		std::string	_getInputIndex(void);
		std::string	_displayFormattedData(const std::string& data);
};

#endif
