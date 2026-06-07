/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 19:19:21 by kjroydev          #+#    #+#             */
/*   Updated: 2026/06/07 17:14:14 by kmarrero         ###   ########.fr       */
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
	std::cout << "Int constructor called" << std::endl;
	this->fixed_value = number << fract_;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
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
	return ((int)this->fixed_value >> fract_);
}

Fixed::~Fixed()
{
	std::cout << "Desctructor called" << std::endl;
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

float	Fixed::operator+(const Fixed& fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(const Fixed& fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(const Fixed& fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

