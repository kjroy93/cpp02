/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:24:46 by kmarrero          #+#    #+#             */
/*   Updated: 2026/07/06 17:21:01 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	a(Fixed(0), Fixed(0));
	Point	b(Fixed(5), Fixed(0));
	Point	c(Fixed(0), Fixed(5));
	Point	op;
	bool	answer;
	{
		Point	point(Fixed(2), Fixed(0));
		std::cout << "Point a: " << a.getX() << ", " << a.getY() << std::endl;
		std::cout << "Point b: " << b.getX() << ", " << b.getY() << std::endl;
		std::cout << "Point c: " << a.getX() << ", " << c.getY() << std::endl;
		std::cout << "Point : " << point.getX() << ", " << point.getY() << std::endl;
		answer = op.bsp(a, b, c, point);
		if (!answer)
			std::cout << "Point it's outside of the triangle" << std::endl;
		else
			std::cout << "Point it's inside of the triangle" << std::endl;
	}
	std::cout << "======================================" << std::endl;
	{
		Point	point(Fixed(1), Fixed(2));
		std::cout << "Point a: " << a.getX() << " " << a.getY() << std::endl;
		std::cout << "Point b: " << b.getX() << " " << b.getY() << std::endl;
		std::cout << "Point c: " << a.getX() << " " << c.getY() << std::endl;
		std::cout << "Point : " << point.getX() << " " << point.getY() << std::endl;
		answer = op.bsp(a, b, c, point);
		if (!answer)
			std::cout << "Point it's outside of the triangle" << std::endl;
		else
			std::cout << "Point it's inside of the triangle" << std::endl;
	}
	std::cout << "======================================" << std::endl;
	{
		Point	point(Fixed(5), Fixed(5));
		std::cout << "Point a: " << a.getX() << " " << a.getY() << std::endl;
		std::cout << "Point b: " << b.getX() << " " << b.getY() << std::endl;
		std::cout << "Point c: " << a.getX() << " " << c.getY() << std::endl;
		std::cout << "Point : " << point.getX() << " " << point.getY() << std::endl;
		answer = op.bsp(a, b, c, point);
		if (!answer)
			std::cout << "Point it's outside of the triangle" << std::endl;
		else
			std::cout << "Point it's inside of the triangle" << std::endl;
	}
	return (0);
}
