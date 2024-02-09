/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 01:41:09 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/07 18:12:35 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <limits>

# define INVALID_CARACTER_PHONE "Error: Invalid character in phone number."
# define INVALID_PHONE "Error: Invalid phone number length."
# define INVALID_CARACTER "Error: Invalid character."
# define VALID_INPUT "Please enter a valid "

class	Contact
{
	public:
		Contact(void);
		void		getContactData(void);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickname(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkestSecret(void);
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
		void		_removeOuterSpaces(std::string& data);
		void		_removeConsecutiveSpaces(std::string& data);
		void		_cleanContactData(std::string& data);
		bool		_validatePhoneCharacters(std::string& phone_number);
		void		_validatePhoneLength(std::string& phone_number);
		void		_verifyPhoneNumber(std::string& phone_number);
		void		_verifyCharacters(std::string& contact_data);
		void		_assignData(const std::string contact_data[]);
		void		_getInput(const std::string& field, std::string& data, int index);	
};

#endif
