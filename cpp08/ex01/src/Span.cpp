/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 04:01:09 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/05 04:11:04 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::~Span() {}

void	Span::addNumber(int num) {
	if (_numbers.size() >= _N) {
		throw std::out_of_range("Cannot add more numbers, maximum limit reached.");
	}
	_numbers.push_back(num);
}

int	Span::shortestSpan() {
	if (_numbers.size() <= 1) {
		throw std::logic_error("Not enough numbers to calculate span.");
	}

	_numbers.sort();

	int minSpan = std::numeric_limits<int>::max();

	std::list<int>::iterator it = _numbers.begin();
	std::list<int>::iterator nextIt = it;
	++nextIt;
	while (nextIt != _numbers.end()) {
		int span = *nextIt - *it;
		if (span < minSpan) {
			minSpan = span;
		}
		++it;
		++nextIt;
	}

	return (minSpan);
}

int	Span::longestSpan() {
	if (_numbers.size() <= 1) {
		throw std::logic_error("Not enough numbers to calculate span.");
	}

	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

	return (maxVal - minVal);
}

void	Span::addNumbers(std::list<int>::iterator begin, std::list<int>::iterator end) {
	while (begin != end) {
		addNumber(*begin);
		++begin;
	}
}
