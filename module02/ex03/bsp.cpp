/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:48:44 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/28 09:45:59 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed calculateCrossProduct(
	const Point &edgeStart, const Point &edgeEnd, const Point &testPoint)
{
	Fixed edgeX = edgeEnd.getX() - edgeStart.getX();
	Fixed edgeY = edgeEnd.getY() - edgeStart.getY();
	Fixed pointX = testPoint.getX() - edgeStart.getX();
	Fixed pointY = testPoint.getY() - edgeStart.getY();

	return edgeX * pointY - edgeY * pointX;
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	bool all_positive;
	bool all_negative;
	Fixed cross1 = calculateCrossProduct(a, b, point);
	Fixed cross2 = calculateCrossProduct(b, c, point);
	Fixed cross3 = calculateCrossProduct(c, a, point);

	if (cross1 == Fixed(0) || cross2 == Fixed(0) || cross3 == Fixed(0))
		return false;
	all_positive = cross1 > Fixed(0) &&
				   cross2 > Fixed(0) &&
				   cross3 > Fixed(0);
	all_negative = cross1 < Fixed(0) &&
				   cross2 < Fixed(0) &&
				   cross3 < Fixed(0);

	return (all_positive || all_negative);
}
