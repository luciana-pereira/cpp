/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:11:43 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/17 05:12:16 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main(void)
{
	try {
		Bureaucrat highGradeBureaucrat("John", 1);
		std::cout << highGradeBureaucrat << std::endl;

		Bureaucrat lowGradeBureaucrat("Jane", 150);
		std::cout << lowGradeBureaucrat << std::endl;

		// Test ShrubberyCreationForm
		ShrubberyCreationForm shrubberyForm("Home");
		std::cout << shrubberyForm << std::endl;

		shrubberyForm.beSigned(highGradeBureaucrat);
		highGradeBureaucrat.executeForm(shrubberyForm);

		// Test RobotomyRequestForm
		RobotomyRequestForm robotomyForm("Target");
		std::cout << robotomyForm << std::endl;

		robotomyForm.beSigned(lowGradeBureaucrat);
		lowGradeBureaucrat.executeForm(robotomyForm);

		// Test PresidentialPardonForm
		PresidentialPardonForm pardonForm("Criminal");
		std::cout << pardonForm << std::endl;

		pardonForm.beSigned(highGradeBureaucrat);
		highGradeBureaucrat.executeForm(pardonForm);	
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}


