/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:54:09 by kmarrero          #+#    #+#             */
/*   Updated: 2026/07/06 17:32:12 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_value = raw;
}

int		Fixed::getRawBits(void) const
{
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

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return (out);
}

bool	Fixed::operator<(const Fixed& fixed) const
{
	return (this->fixed_value < fixed.getRawBits());
}

bool	Fixed::operator>(const Fixed& fixed) const
{
	return (this->fixed_value > fixed.getRawBits());
}

bool	Fixed::operator>=(const Fixed& fixed) const
{
	return (this->fixed_value >= fixed.getRawBits());
}

bool	Fixed::operator<=(const Fixed& fixed) const
{
	return (this->fixed_value <= fixed.getRawBits());
}

bool	Fixed::operator!=(const Fixed& fixed) const
{
	return (this->fixed_value != fixed.getRawBits());
}

bool	Fixed::operator==(const Fixed& fixed) const
{
	return (this->fixed_value == fixed.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& fixed) const
{
	Fixed	result;

	result.fixed_value = this->fixed_value + fixed.fixed_value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& fixed) const
{
	Fixed	result;

	result.fixed_value = this->fixed_value - fixed.fixed_value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& fixed) const
{
	Fixed	result;
	long	tmp;

	tmp = (long)this->fixed_value * (long)fixed.fixed_value;
	result.fixed_value = tmp >> fract_;
	return (result);
}

Fixed	Fixed::operator/(const Fixed& fixed) const
{
	Fixed	result;
	long	tmp;

	tmp = ((long)this->fixed_value << fract_) / fixed.fixed_value;
	result.fixed_value = tmp;
	return (result);
}

Fixed&	Fixed::operator++()
{
	this->fixed_value++;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->fixed_value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp;

	tmp = *this;
	this->fixed_value++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp;

	tmp = *this;
	this->fixed_value--;
	return (tmp);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return (f2);
	else
		return (f1);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 > f2)
		return (f2);
	else
		return (f1);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}
