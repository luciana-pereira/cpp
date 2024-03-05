/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:01:23 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/05 00:02:32 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : elements(NULL), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : size_(n) {
	elements = new T[size_];
}

template <typename T>
Array<T>::Array(const Array<T>& other) : size_(other.size_) {
	elements = new T[size_];
	for (unsigned int i = 0; i < size_; ++i) {
		elements[i] = other.elements[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		delete[] elements;
		size_ = other.size_;
		elements = new T[size_];
		for (unsigned int i = 0; i < size_; ++i) {
			elements[i] = other.elements[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= size_) {
		throw std::out_of_range("Index out of bounds");
	}
	return elements[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return size_;
}
