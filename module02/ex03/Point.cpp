/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:15:45 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/27 13:55:20 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		const_cast<Fixed &>(_x) = other._x;
		const_cast<Fixed &>(_y) = other._y;
	}
	return *this;
}

Point::~Point(void)
{
}

Fixed Point::getX(void) const
{
	return _x;
}

Fixed Point::getY(void) const
{
	return _y;
}
