/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 03:54:39 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/15 05:50:32 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

// Iterador 
template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value); // Procura pelo valor no container

	if (it == container.end()) { // // Se o valor não for encontrado
		throw std::runtime_error("Value not found in container"); ///Lança uma execeção
	}

	return (it); // Retorna o iterador para o valor encontrado
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int value) {
	const typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	
	if (it == container.end()) {
		throw std::runtime_error("Value not found in container");
	}

	return (it);
}

#endif
