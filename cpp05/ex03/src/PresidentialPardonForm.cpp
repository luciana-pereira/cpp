/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:14:28 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/12 16:54:01 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& form)
	: AForm("PresidentialPardonForm", 25, 5), _target(form._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& form)
{
	AForm::operator=(form);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

bool	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	try {
		if (executor.getGrade() > getGradeToExecute() || executor.getGrade() < 0)
			throw AForm::GradeTooLowException();
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		return (false);
	}
	return (true);
}
