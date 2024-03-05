/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:10:21 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/04 23:18:27 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *array, const size_t length, void (*func)(T &element)) {
	for (size_t index = 0; index < length; ++index) {
		func(array[index]);
	}
}

template <typename T>
void	iter(T const *array, const size_t length, void (*func)(const T &element)) {
	for (size_t index = 0; index < length; ++index) {
		func(array[index]);
	}
}

template <typename T>
void	printElement(T &element) {
	std::cout << element << " ";
}

template <typename T>
void	printElement(const T &element) {
	std::cout << element << " ";
}

#endif
