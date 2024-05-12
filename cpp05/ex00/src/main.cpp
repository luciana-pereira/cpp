/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:11:43 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/12 17:45:19 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

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
		std::cout << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}
