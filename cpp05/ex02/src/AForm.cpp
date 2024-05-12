/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 03:39:47 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/12 17:47:43 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char* AForm::FormIsNotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

AForm::AForm(void)
	: _name("Unnamed"), _signed(false), _gradeToSign(150), _gradeToExecute(1)
{}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	try {
		if (gradeToSign > 150 || gradeToExecute > 150)
			throw AForm::GradeTooLowException();
		else if (gradeToSign < 1 || gradeToExecute < 1)
			throw AForm::GradeTooHighException();
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	_signed = false;
}

AForm::AForm(AForm& form)
	: _name(form._name), _signed(false), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute)
{
	try {
		if (form._gradeToSign > 150 || form._gradeToExecute > 150)
			throw AForm::GradeTooLowException();
		else if (form._gradeToSign < 1 || form._gradeToExecute < 1)
			throw AForm::GradeTooHighException();
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
}

AForm& AForm::operator=(AForm& form)
{
	try {
		if (form._gradeToSign > 150 || form._gradeToExecute > 150)
			throw AForm::GradeTooLowException();
		else if (form._gradeToSign < 1 || form._gradeToExecute < 1)
			throw AForm::GradeTooHighException();
		_signed = false;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	
	return (*this);
}

AForm::~AForm(void) {}

const	std::string& AForm::getName(void) const
{
	return (_name);
}

bool	AForm::isSigned(void) const
{
	return (_signed);
}

int	AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	try {
		if (bureaucrat.getGrade() != -1 && bureaucrat.getGrade() > _gradeToSign)
			throw AForm::GradeTooLowException();
		_signed = true;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		_signed = false;
	}
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form: " << form.getName() << ", Grade to Sign: " << form.getGradeToSign()
		<< ", Grade to Execute: " << form.getGradeToExecute() << ", Signed: ";
	if (form.isSigned())
		os << "Yes";
	else
		os << "No";
	return (os);
}
