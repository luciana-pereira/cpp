/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 03:50:49 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/12 17:24:49 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <ostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class	AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class FormIsNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	AForm(void);
	AForm(AForm& form);
	AForm(const std::string name, int gradeToSign, int gradeToExecute);
	AForm&	operator=(AForm& form);
	virtual	~AForm(void);
	std::string	getName(void) const;
	bool	isSigned(void) const;
	int	getGradeToSign(void) const;
	int	getGradeToExecute(void) const;
	void	beSigned(Bureaucrat& bureaucrat);
	virtual bool execute(Bureaucrat const& executor) const = 0;
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
