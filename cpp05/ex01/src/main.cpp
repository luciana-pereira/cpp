/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:11:43 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/12 17:46:22 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int	main(void)
{
	try {
		std::cout << " ========= Init Test ========= " << std::endl;
		std::cout << "\n ====== Creat Bureaucrat ===== \n" << std::endl;

		Bureaucrat highGradeBureaucrat("John", 1);
		std::cout << highGradeBureaucrat << std::endl;

		Bureaucrat lowGradeBureaucrat("Jane", 150);
		std::cout << lowGradeBureaucrat << std::endl;

		std::cout << "\n=== Higher or Lower Grade ====\n" << std::endl;
		
		highGradeBureaucrat.incrementGrade();
		std::cout << highGradeBureaucrat << std::endl;

		lowGradeBureaucrat.decrementGrade();
		std::cout << lowGradeBureaucrat << std::endl;

		std::cout << "\n======= Invalid Grade ========\n" << std::endl;

		Bureaucrat invalidGradeBureaucrat("Invalid", 151);

		std::cout << "\nCreating and displaying a form: \n" << std::endl;
		
		Form form("Important Form", 5, 10);
		std::cout << form << std::endl;

		std::cout << "\nSignature of the form by a high-ranking bureaucrat: \n" << std::endl;

		form.beSigned(highGradeBureaucrat);
		std::cout << form << std::endl;

		std::cout << "\nAttempt to sign the form by a low-level bureaucrat: \n" << std::endl;

		form.beSigned(lowGradeBureaucrat);
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
