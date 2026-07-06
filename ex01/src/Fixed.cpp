/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:53:47 by kmarrero          #+#    #+#             */
/*   Updated: 2026/07/06 14:55:41 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const int number)
{
	const int max_int = INT_MAX / (1 << fract_);
	const int min_int = INT_MIN / (1 << fract_);

	std::cout << "Int constructor called" << std::endl;
	if (number > max_int)
	{
		this->fixed_value = max_int << fract_;
		return ;
	}
	if (number < min_int)
	{
		this->fixed_value = min_int * (1 << fract_);
		return ;
	}
	this->fixed_value = number << fract_;
}

Fixed::Fixed(const float number)
{
	const float max_fixed = static_cast<float>(INT_MAX) / (1 << fract_);
	const float min_fixed = static_cast<float>(INT_MIN) / (1 << fract_);

	std::cout << "Float constructor called" << std::endl;
	if (number > max_fixed)
	{
		this->fixed_value = INT_MAX;
		return ;
	}
	if (number < min_fixed)
	{
		this->fixed_value = INT_MIN;
		return ;
	}
	this->fixed_value = roundf(number * (1 << fract_));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixed_value = other.fixed_value;
	return (*this);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_value = raw;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_value);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixed_value / (1 << fract_));
}

int		Fixed::toInt(void) const
{
	return ((int)this->fixed_value / (1 << fract_));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return (out);
}
