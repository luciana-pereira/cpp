/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 07:06:16 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 07:28:18 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "../include/Fixed.hpp"

#include <iostream>

class	Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &src);
	~Point();
	Point &operator=(const Point &rhs);
	Fixed getX(void) const;
	Fixed getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif
