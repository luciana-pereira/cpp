/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:11:43 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/12 17:48:25 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int	main(void)
{
	try {
		Bureaucrat highGradeBureaucrat("John", 1);
		std::cout << highGradeBureaucrat << std::endl;

		Bureaucrat lowGradeBureaucrat("Jane", 150);
		std::cout << lowGradeBureaucrat << std::endl;

		std::cout << "\n======= Test ShrubberyCreationForm ========\n" << std::endl;
		ShrubberyCreationForm shrubberyForm("Home");

		shrubberyForm.beSigned(highGradeBureaucrat);
		highGradeBureaucrat.executeForm(shrubberyForm);
		
		std::cout << shrubberyForm << std::endl;

		std::cout << "\n======== Test RobotomyRequestForm =========\n" << std::endl;
		RobotomyRequestForm robotomyForm("Target");

		robotomyForm.beSigned(highGradeBureaucrat);
		highGradeBureaucrat.executeForm(robotomyForm);
		
		std::cout << robotomyForm << std::endl;

		std::cout << "\n****RobotomyRequestForm not executed, grade is too low!\n" << std::endl;
		RobotomyRequestForm robotomyForm1("Target1");
		
		robotomyForm1.beSigned(lowGradeBureaucrat);
		lowGradeBureaucrat.executeForm(robotomyForm1);
		
		std::cout << robotomyForm1 << std::endl;

		std::cout << "\n======= Test PresidentialPardonForm =======\n" << std::endl;
		PresidentialPardonForm pardonForm("Criminal");
		
		pardonForm.beSigned(highGradeBureaucrat);
		highGradeBureaucrat.executeForm(pardonForm);

		std::cout << pardonForm << std::endl;
		
		std::cout << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
