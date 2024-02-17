/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:12:00 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/17 06:37:15 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form)
	: AForm("ShrubberyCreationForm", 145, 137), _target(form._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form)
{
	AForm::operator=(form);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

bool	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	try {
		if (executor.getGrade() > getGradeToExecute() || executor.getGrade() < 0)
			throw  AForm::GradeTooLowException();
		std::ofstream file((_target + "_shrubbery").c_str());
		file << "       ^" << std::endl;
		file << "      / \\" << std::endl;
		file << "     /   \\" << std::endl;
		file << "    /     \\" << std::endl;
		file << "   /       \\" << std::endl;
		file << "  /         \\" << std::endl;
		file << " /           \\" << std::endl;
		file << "/             \\" << std::endl;
		file << "     |" << std::endl;
		file.close();
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		return (false);
	}
	return (true);
}
