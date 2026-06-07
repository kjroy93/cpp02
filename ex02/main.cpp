/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:08:25 by kmarrero          #+#    #+#             */
/*   Updated: 2026/06/07 19:09:32 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed e;
	Fixed const f( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << e << std::endl;
	std::cout << ++e << std::endl;
	std::cout << e << std::endl;
	std::cout << e++ << std::endl;
	std::cout << e << std::endl;

	std::cout << f << std::endl;

	std::cout << Fixed::max( e, f ) << std::endl;
	
	std::cout << e << std::endl;
	std::cout << --e << std::endl;
	std::cout << e << std::endl;
	std::cout << e-- << std::endl;
	std::cout << e << std::endl;
	std::cout << Fixed::min( e, f ) << std::endl;

	std::cout << "===============" << std::endl;

	Fixed	a;
	Fixed	const b( 10 );
	Fixed	const c(42.42f);
	Fixed	const d( b );

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "d is less than c: " << (d < c) << std::endl;
	std::cout << "d is less than b: " << (d < b) << std::endl;
	std::cout << "d is greater than c: " << (d > c) << std::endl;
	std::cout << "d is greater than b: " << (d > b) << std::endl;
	std::cout << "d is less than or equal to c: " << (d <= c) << std::endl;
	std::cout << "d is less than or equal to b: " << (d <= b) << std::endl;
	std::cout << "d is greater than or equal to c: " << (d >= c) << std::endl;
	std::cout << "d is greater than or equal to b: " << (d >= b) << std::endl;
	std::cout << "d is equal to c: " << (d == c) << std::endl;
	std::cout << "d is equal to b: " << (d == b) << std::endl;
	std::cout << "d is not equal to c: " << (d != c) << std::endl;
	std::cout << "d is not equal to b: " << (d != b) << std::endl;

	std::cout << "d + c = " << (d + c) << std::endl;
	std::cout << "d + b = " << (d + b) << std::endl;
	std::cout << "d - c = " << (d - c) << std::endl;
	std::cout << "c - d = " << (c - d) << std::endl;
	std::cout << "b - d = " << (b - d) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "b * d = " << (b * d) << std::endl;
	std::cout << "b / d = " << (b / d) << std::endl;
	std::cout << "c / d = " << (c / d) << std::endl;

	
	return (0);
}