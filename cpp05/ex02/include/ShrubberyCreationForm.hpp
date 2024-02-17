/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:33:12 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/17 06:34:49 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class	ShrubberyCreationForm : public AForm
{
private:
	const std::string _target;
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& form);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);
	~ShrubberyCreationForm(void);
	bool	execute(const Bureaucrat& executor) const;
};

#endif
