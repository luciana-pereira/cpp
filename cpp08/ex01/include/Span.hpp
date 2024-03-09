/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 04:01:09 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/05 04:11:04 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <limits>
#include <list>

class	Span {
public:
	Span(unsigned int N);
	~Span();

	void	addNumber(int number);
	int		shortestSpan();
	int		longestSpan();
	void	addNumbers(std::list<int>::iterator begin, std::list<int>::iterator end);
private:
    unsigned int _N;
    std::list<int> _numbers;
};

#endif
