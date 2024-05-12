/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:48:17 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/12 02:28:50 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <stdlib.h>
#include <ostream>

class	RobotomyRequestForm : public AForm
{
private:
	const std::string _target;
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(RobotomyRequestForm& form);
	RobotomyRequestForm& operator=(RobotomyRequestForm& form);
	~RobotomyRequestForm(void);
	bool	execute(Bureaucrat const& executor) const;
};

#endif
