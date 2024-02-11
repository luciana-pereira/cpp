/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 06:41:19 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 06:45:06 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

static Fixed	abs(Fixed x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

static Fixed	area(Point const a, Point const b, Point const c)
{
	return (((a.getX() * (b.getY() - c.getY())) +
			(b.getX() * (c.getY() - a.getY())) +
			(c.getX() * (a.getY() - b.getY()))) /
			2);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed abcArea = abs(area(a, b, c));
	Fixed pabArea = abs(area(point, a, b));
	Fixed pbcArea = abs(area(point, b, c));
	Fixed pcaArea = abs(area(point, c, a));
	return (abcArea == pabArea + pbcArea + pcaArea);
}
