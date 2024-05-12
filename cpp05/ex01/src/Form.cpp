/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 03:39:47 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/12 07:15:58 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

Form::Form(void) : _name("Unnamed"), _signed(false),  _gradeToSign(150), _gradeToExecute(1)
{}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	try {
		if (gradeToSign > 150 || gradeToExecute > 150)
			throw Form::GradeTooLowException();
		else if (gradeToSign < 1 || gradeToExecute < 1)
			throw Form::GradeTooHighException();
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	_signed = false;
}

Form::Form(Form& form)
	: _name(form._name), _signed(false), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute)
{
	try {
		if (form._gradeToSign > 150 || form._gradeToExecute > 150)
			throw Form::GradeTooLowException();
		else if (form._gradeToSign < 1 || form._gradeToExecute < 1)
			throw Form::GradeTooHighException();
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
}

Form& Form::operator=(Form& form)
{
	try {
		if (form._gradeToSign > 150 || form._gradeToExecute > 150)
			throw Form::GradeTooLowException();
		else if (form._gradeToSign < 1 || form._gradeToExecute < 1)
			throw Form::GradeTooHighException();
		_signed = false;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	return *this;
}

Form::~Form(void) {}

const	std::string& Form::getName(void) const
{
	return (_name);
}

bool	Form::getIsSigned(void) const
{
	return (_signed);
}

int	Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	try {
		if (bureaucrat.getGrade() != -1 && bureaucrat.getGrade() > _gradeToSign)
			throw Form::GradeTooLowException();
		_signed = true;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		_signed = false;
	}
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName() << ", Grade to Sign: " << form.getGradeToSign()
		<< ", Grade to Execute: " << form.getGradeToExecute() << ", Signed: ";
	if (form.getIsSigned())
		os << "Yes";
	else
		os << "No";
	return os;
}
