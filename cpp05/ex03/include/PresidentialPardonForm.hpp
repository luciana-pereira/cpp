/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:43:55 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/12 16:48:47 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm& form);
	PresidentialPardonForm& operator=(PresidentialPardonForm& form);
	virtual ~PresidentialPardonForm(void);
	virtual bool	execute(Bureaucrat const& executor) const;
};

#endif
