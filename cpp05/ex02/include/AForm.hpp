/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 03:50:49 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/12 02:02:59 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <ostream>
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
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
	class FormIsNotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};
	AForm(void);
	AForm(AForm& form);
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm& operator=(AForm& form);
	~AForm(void);
	const	std::string& getName(void) const;
	bool	isSigned(void) const;
	int	getGradeToSign(void) const;
	int	getGradeToExecute(void) const;
	void	beSigned(const Bureaucrat& bureaucrat);
	virtual bool execute(Bureaucrat const& executor) const = 0;
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
