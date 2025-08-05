/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:36 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/05 14:34:22 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * 		(1 << bits) = 2^bits = pow(2, bits)
 */

Fixed::Fixed()
{	
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	if (value > static_cast<int>(roundf(INT_MAX / (1 << _bits))))
		std::cout << "\e[1;31mGiven value is greater than max representable value\e[0m" << std::endl;
	if (value < static_cast<int>(roundf(INT_MIN / (1 << _bits))))
		std::cout << "\e[1;31mGiven value is lower than min representable value\e[0m" << std::endl;
	this->_value = value << _bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	if (value > INT_MAX / (1 << _bits))
		std::cout << "\e[1;31mGiven value exeeds max representable value\e[0m" << std::endl;
	if (value < INT_MIN / (1 << _bits))
		std::cout << "\e[1;31mGiven value is lower than min representable value\e[0m" << std::endl;
	this->_value = roundf(value * ( 1 << _bits));
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
	this->_value = a.getRawBits();
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
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_value) / static_cast<float>(1 << _bits));
}

int	Fixed::toInt( void ) const
{
	return (this->_value >> _bits);
}