/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:48:44 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/30 20:57:41 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed fixedAbs(const Fixed &num)
{
	return (num < Fixed()) ? num * Fixed(-1) : num;
}

static Fixed calculateArea(const Point &a, const Point &b, const Point &c)
{
	Fixed area = (a.getX() * (b.getY() - c.getY()) +
				  b.getX() * (c.getY() - a.getY()) +
				  c.getX() * (a.getY() - b.getY())) /
				 Fixed(2);

	return fixedAbs(area);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed triangleArea;
	Fixed area[3];
	Fixed result;

	triangleArea = calculateArea(a, b, c);
	if (triangleArea == Fixed(0))
		return false;
	area[0] = calculateArea(point, a, b);
	area[1] = calculateArea(point, b, c);
	area[2] = calculateArea(point, c, a);
	if (area[0] == Fixed(0) || area[1] == Fixed(0) || area[2] == Fixed(0))
		return false;
	result = area[0] + area[1] + area[2] - triangleArea;
	if (fixedAbs(result) == Fixed(0))
		return true;
	return false;
}
