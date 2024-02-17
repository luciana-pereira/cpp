/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:48:17 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/17 06:10:07 by lucperei         ###   ########.fr       */
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
	const std::string _target;
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& form);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& form);
	~RobotomyRequestForm(void);
	bool	execute(const Bureaucrat& executor) const;
};

#endif
