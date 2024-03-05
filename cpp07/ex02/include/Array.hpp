/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:57:49 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/05 00:53:23 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class Array {
private:
	T* elements;
	unsigned int size_;
public:
	Array();
	~Array();
	Array(const Array<T>& other);
	explicit Array(unsigned int n);
	Array<T>& operator=(const Array<T>& other);
	T& operator[](unsigned int index);
	unsigned int size() const;
};

#include "./Array.tpp"

#endif
