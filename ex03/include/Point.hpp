/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:05:18 by kmarrero          #+#    #+#             */
/*   Updated: 2026/07/06 16:56:20 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class	Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const Fixed& x, const Fixed& y);
		Point(const Point& other);
		Point&	operator=(const Point& other);
		~Point();
		Point	operator-(const Point& other) const;
		Fixed	cross(const Point& other) const;
		bool	bsp(Point const a, Point const b, Point const c, Point const point);
		Fixed	getX(void);
		Fixed	getY(void);
};

#endif