/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:21:54 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/17 20:52:31 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &obj) {
    (void)obj;
}

Intern& Intern::operator=(const Intern &obj)
{
	(void)obj;
	return (*this);
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    AForm* form = NULL;

    if (formName == "presidential pardon")
        form = new PresidentialPardonForm(target);
    else if (formName == "robotomy request")
        form = new RobotomyRequestForm(target);
    else if (formName == "shrubbery creation")
        form = new ShrubberyCreationForm(target);
    else
        std::cout << "Error: Form " << formName << " does not exist." << std::endl;

    if (form)
        std::cout << "Intern creates " << formName << std::endl;

    return (form);
}
