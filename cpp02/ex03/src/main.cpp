/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:50:55 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 07:34:45 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

int main(void) {
	Point pIn(10, 15);
	Point pOut1(5, 5);
	Point pOut2(25, 5);

	if (bsp(Point(0, 0), Point(10, 30), Point(20, 0), pIn)) {
		std::cout << "Point (" << pIn.getX() << ", " << pIn.getY() << ")"
				  << "is inside the triangle." << std::endl;
	} else {
		std::cout << "Point (" << pIn.getX() << ", " << pIn.getY() << ")"
				  << " is not in the triangle." << std::endl;
	}

	if (bsp(Point(0, 0), Point(10, 30), Point(20, 0), pOut1)) {
		std::cout << "Point (" << pOut1.getX() << ", " << pOut1.getY() << ")"
				  << " is inside the triangle." << std::endl;
	} else {
		std::cout << "Point (" << pOut1.getX() << ", " << pOut1.getY() << ")"
				  << " is not in the triangle." << std::endl;
	}

	if (bsp(Point(0, 0), Point(10, 30), Point(20, 0), pOut2)) {
		std::cout << "Point (" << pOut2.getX() << ", " << pOut2.getY() << ")"
				  << " is inside the triangle." << std::endl;
	} else {
		std::cout << "Point (" << pOut2.getX() << ", " << pOut2.getY() << ")"
				  << " is not in the triangle." << std::endl;
	}
    return (0);
}

