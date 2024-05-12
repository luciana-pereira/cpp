/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:41:42 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/12 18:42:17 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class	Intern
{
public:
	Intern(void);
	Intern(Intern &obj);
	virtual ~Intern(void);
	Intern &operator=(Intern &obj);
	AForm* makeForm(const std::string& formName, const std::string& target);
private:
	struct FormCreationInfo {
		const char* formName;
		AForm* (*createForm)(const std::string& target);
	};
};

#endif
