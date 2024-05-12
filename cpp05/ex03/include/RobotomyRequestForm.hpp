/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:48:17 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/12 16:48:22 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ostream>

class	RobotomyRequestForm : public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm& form);
	RobotomyRequestForm& operator=(RobotomyRequestForm& form);
	virtual ~RobotomyRequestForm(void);
	virtual bool	execute(Bureaucrat const& executor) const;
};

#endif
