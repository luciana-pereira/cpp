/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:11:43 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/16 05:43:51 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat highGradeBureaucrat("John", 1);
		std::cout << highGradeBureaucrat << std::endl;

		Bureaucrat lowGradeBureaucrat("Jane", 150);
		std::cout << lowGradeBureaucrat << std::endl;

		highGradeBureaucrat.incrementGrade();
		std::cout << highGradeBureaucrat << std::endl;

		lowGradeBureaucrat.decrementGrade();
		std::cout << lowGradeBureaucrat << std::endl;

		// Trying to create a bureaucrat with an invalid grade
		Bureaucrat invalidGradeBureaucrat("Invalid", 151);
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}

