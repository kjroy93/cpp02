/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:22:32 by kmarrero          #+#    #+#             */
/*   Updated: 2026/07/06 17:03:49 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
	:x(0),
	y(0)
{
}

Point::Point(const Fixed& x, const Fixed& y)
	:x(x),
	y(y)
{
}

Point::Point(const Point& other)
	:x(other.x),
	y(other.y)
{
}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

Point::~Point()
{
}


Point	Point::operator-(const Point& other) const
{
	return (Point(
		x - other.x, y - other.y
	));
}

Fixed	Point::cross(const Point& other) const
{
	return (Fixed(
		x * other.y - y * other.x
	));
}

Fixed	Point::getX(void)
{
	return (this->x);
}

Fixed	Point::getY(void)
{
	return (this->y);
}
