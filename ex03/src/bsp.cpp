/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:28:16 by kmarrero          #+#    #+#             */
/*   Updated: 2026/07/06 17:05:40 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point	ab = b - a;
	Point	bc = c - b;
	Point	ca = a - c;
	
	Point	ap = point - a;
	Point	bp = point - b;
	Point	cp = point - c;
	
	Fixed	ab_answer = ab.cross(ap);
	Fixed	bc_answer = bc.cross(bp);
	Fixed	ca_answer = ca.cross(cp);

	std::cout << "Point ab: " << ab_answer.toInt() << std::endl;
	std::cout << "Point bc: " << bc_answer.toInt() << std::endl;
	std::cout << "Point ca: " << ca_answer.toInt() << std::endl;
	if ((ab_answer > 0 && bc_answer > 0 && ca_answer > 0) ||
		(ab_answer < 0 && bc_answer < 0 && ca_answer < 0))
		return (true);
	return (false);
}
