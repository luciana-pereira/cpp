/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:46:34 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/17 06:44:25 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", 72, 45), _target("default") {}
	
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form)
	: AForm("RobotomyRequestForm", 72, 45), _target(form._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form)
{
	AForm::operator=(form);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

bool	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	try {
		if (executor.getGrade() > getGradeToExecute() || executor.getGrade() < 0)
			throw AForm::GradeTooLowException();
		std::cout << "blip... bliiiiiiiiiiiiiiiiiiiiiiiiiiiiip..." << std::endl;
		std::srand(time(NULL));
		if ((std::rand() % 2) == 0)
			std::cout << _target << " has been robotomized successfully by " << executor.getName() << std::endl;
		else
			std::cout << "Robotomy on " << _target << " failed." << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		return (false);
	}
	return (true);
}
