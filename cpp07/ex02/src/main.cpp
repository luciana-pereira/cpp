/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:03:12 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/05 00:15:02 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"

int main() {
    Array<int> intArray(5);

    for (unsigned int i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 10;
    }

    for (unsigned int i = 0; i < intArray.size(); ++i) {
        std::cout << "Element " << i << ": " << intArray[i] << std::endl;
    }

    try {
        std::cout << "Trying to access out-of-bounds element: " << intArray[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
