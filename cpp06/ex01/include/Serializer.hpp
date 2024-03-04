/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 03:25:42 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/03 22:45:11 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "../include/Data.hpp"
#include <cstddef>
#include <stdint.h>
// class	Data;

class	Serializer {
public:
	// Serializer() = delete;
	static uintptr_t	serialize(Data* ptr);
	static Data*	deserialize(uintptr_t raw);
};

#endif 