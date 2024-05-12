/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:19:02 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/12 06:55:14 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp" 

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

Bureaucrat::Bureaucrat(void) : _name("Unnamed"), _grade(150)
{ }

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	try {
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		grade = -1;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
		grade = -1;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat &bureaucrat)
{
	try {
		if (bureaucrat.getGrade() > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (bureaucrat.getGrade() < 1)
			throw Bureaucrat::GradeTooHighException();
		_grade = bureaucrat.getGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		_grade = -1;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
		_grade = -1;
	}
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &bureaucrat)
{
	try {
		if (bureaucrat.getGrade() > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (bureaucrat.getGrade() < 1)
			throw Bureaucrat::GradeTooHighException();
		_grade = bureaucrat.getGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		_grade = -1;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
		_grade = -1;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

const	std::string& Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	try {
		if (_grade - 1 > 150)
			throw GradeTooHighException();
		else if (_grade - 1 < 1)
			throw GradeTooHighException();
		_grade--;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade(void)
{
	try {
		if (_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (_grade + 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		_grade++;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::checkSignedForm(AForm &form)
{
	try {
		form.beSigned(*this);
		if (form.isSigned())
			std::cout << _name << " signed form " << form.getName() << std::endl;
		else
			throw AForm::GradeTooLowException();
	} catch (AForm::GradeTooLowException &e) {
		std::cout << _name << " unsigned " << form.getName() << " form" << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form)
{
	try {
		if (!form.isSigned())
			throw AForm::FormIsNotSignedException();
		if (form.execute(*this)) {
			std::cout << _name << " executed " << form.getName() << std::endl;
		}
		else
			throw AForm::GradeTooLowException();
	} catch (AForm::FormIsNotSignedException &e) {
		std::cout << e.what() << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << _name << " execution failure" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
