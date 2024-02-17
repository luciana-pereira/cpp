/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 03:50:49 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/17 03:55:41 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class	Form
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
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& form);
	Form& operator=(const Form& form);
	~Form(void);
	const std::string& getName(void) const;
	bool	isSigned(void) const;
	int	getGradeToSign(void) const;
	int	getGradeToExecute(void) const;
	void	beSigned(const Bureaucrat& bureaucrat);
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif
