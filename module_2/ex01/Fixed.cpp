/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:36 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/18 23:52:58 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * 		(1 << bits) = 2^bits = pow(2, bits)
 */

Fixed::Fixed()
{	
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	if (value > static_cast<int32_t>(roundf(std::numeric_limits<int32_t>::max() / (1 << bits))))
		std::cout << "\e[1;31mGiven value is greater than max representable value\e[0m" << std::endl;
	if (value < static_cast<int32_t>(roundf(std::numeric_limits<int32_t>::min() / (1 << bits))))
		std::cout << "\e[1;31mGiven value is lower than min representable value\e[0m" << std::endl;
	this->value = value << bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	if (value > std::numeric_limits<int32_t>::max() / (1 << bits))
		std::cout << "\e[1;31mGiven value exeeds max representable value\e[0m" << std::endl;
	if (value < std::numeric_limits<int32_t>::min() / (1 << bits))
		std::cout << "\e[1;31mGiven value is lower than min representable value\e[0m" << std::endl;
	this->value = roundf(value * ( 1 << bits));
}

Fixed::~Fixed()
{	std::cout << "Destructor called" << std::endl;	}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = a;
}

Fixed& Fixed::operator=(const Fixed &a)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = a.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &o, const Fixed &a)
{
	o << a.toFloat();
	return (o);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->value) / static_cast<float>(1 << bits));
}

int	Fixed::toInt( void ) const
{
	return (this->value >> bits);
}