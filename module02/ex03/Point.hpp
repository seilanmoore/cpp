/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:15:51 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/30 17:51:23 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include <fstream>

#include "Fixed.hpp"

class Point
{
public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &copy);
	Point &operator=(const Point &copy);
	~Point(void);

	Fixed getX(void) const;
	Fixed getY(void) const;

private:
	const Fixed _x;
	const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
