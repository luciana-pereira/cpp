/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:19:53 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/17 21:32:30 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

#include "AForm.hpp"

class AForm;

class	Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	Bureaucrat(void);
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& bureaucrat);
	Bureaucrat& operator=(const Bureaucrat& bureaucrat);
	~Bureaucrat(void);
	const std::string& getName(void) const;
	int		getGrade(void) const;
	void	incrementGrade(void);
	void	decrementGrade(void);
	void	executeForm(const AForm &form);
	void	checkSignedForm(AForm &form);
};

std::ostream	&operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
