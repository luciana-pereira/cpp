/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 03:39:47 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/12 17:30:40 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

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


// Construtor padrão da classe AForm. Ele inicializa os membros _name, _signed, _gradeToSign e _gradeToExecute com valores padrão.
AForm::AForm(void)
	: _name("Unnamed"), _signed(false), _gradeToSign(150), _gradeToExecute(1)
{}

/*
Construtor sobrecarregado da classe AForm. Ele permite inicializar um objeto AForm com valores 
específicos para _name, _gradeToSign e _gradeToExecute.
*/
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
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

/*
Construtor de cópia da classe AForm. Ele cria uma cópia de outro objeto AForm, copiando os valores 
dos membros _name, _signed, _gradeToSign e _gradeToExecute.
*/
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

/*
Operador de atribuição da classe AForm. Ele permite atribuir o valor de outro objeto AForm a este objeto, copiando os valores dos membros 
_name, _gradeToSign e _gradeToExecute.
*/
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

// Destrutor da classe AForm. Ele não realiza nenhuma operação específica além de ser definido.
AForm::~AForm(void) {}

std::string AForm::getName(void) const
{
	return (_name);
}

bool	AForm::isSigned(void) const
{
	return (_signed);
}

// Método retorna a classificação necessária para assinar o formulário.
int	AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}
 // Método retorna a classificação necessária para executar o formulário.
int	AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

/*
Método permite que um burocrata assine o formulário. Ele verifica se o burocrata tem uma classificação adequada 
para assinar o formulário e, em caso afirmativo, define _signed como verdadeiro.
*/
void	AForm::beSigned(Bureaucrat& bureaucrat)
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

/*
Função de sobrecarga do operador de inserção <<, que permite imprimir as informações do formulário em um fluxo de saída, como std::cout. 
Ele imprime o nome do formulário, a classificação necessária para assinar, a classificação necessária para executar e se o formulário está assinado ou não.
*/
std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	os << "Form: " << form.getName() << ", Grade to Sign: " << form.getGradeToSign()
		<< ", Grade to Execute: " << form.getGradeToExecute() << ", Signed: ";
	if (form.isSigned())
		os << "Yes";
	else
		os << "No";
	return (os);
}
