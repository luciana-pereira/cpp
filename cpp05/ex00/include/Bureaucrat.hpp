/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:19:53 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/11 19:24:47 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class	Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
	Bureaucrat(void);
	Bureaucrat(Bureaucrat& bureaucrat);
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat& operator=(Bureaucrat& bureaucrat);
	~Bureaucrat(void);
	const std::string& getName(void) const;
	int		getGrade(void) const;
	void	incrementGrade(void);
	void	decrementGrade(void);
};

std::ostream	&operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
