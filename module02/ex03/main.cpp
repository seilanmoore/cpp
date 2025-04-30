/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:15:08 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/30 20:56:42 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static void test_bsp(const Point a, const Point b, const Point c, const Point point, bool expected)
{
	bool result = bsp(a, b, c, point);
	std::cout << "Point (" << point.getX() << ", " << point.getY() << ") is ";
	if (result == expected)
	{
		std::cout << (result ? "inside" : "outside") << " the triangle. [PASSED]" << std::endl;
	}
	else
	{
		std::cout << (result ? "inside" : "outside") << " the triangle, but expected to be "
				  << (expected ? "inside" : "outside") << ". [FAILED]" << std::endl;
	}
}

int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(0.0f, 5.0f);

	// Test points inside the triangle
	test_bsp(a, b, c, Point(1.0f, 1.0f), true);
	test_bsp(a, b, c, Point(2.0f, 2.0f), true);
	test_bsp(a, b, c, Point(0.5f, 0.5f), true);
	test_bsp(a, b, c, Point(2.0f, 0.1f), true);

	// Test points outside the triangle
	test_bsp(a, b, c, Point(6.0f, 6.0f), false);
	test_bsp(a, b, c, Point(-1.0f, -1.0f), false);
	test_bsp(a, b, c, Point(3.0f, 4.0f), false);

	// Test points on the edges of the triangle
	test_bsp(a, b, c, Point(2.5f, 0.0f), false);
	test_bsp(a, b, c, Point(0.0f, 2.5f), false);
	test_bsp(a, b, c, Point(2.5f, 2.5f), false);

	// Test points at the vertices of the triangle
	test_bsp(a, b, c, Point(0.0f, 0.0f), false);
	test_bsp(a, b, c, Point(5.0f, 0.0f), false);
	test_bsp(a, b, c, Point(0.0f, 5.0f), false);
	return 0;
}
