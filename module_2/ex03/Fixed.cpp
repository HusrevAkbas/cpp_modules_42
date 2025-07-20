/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:36 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/20 22:20:03 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * 		(1 << bits) = 2^bits = pow(2, bits)
 */

Fixed::Fixed()
{	
	//	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int value)
{
	//	std::cout << "Int constructor called" << std::endl;
	if (value > static_cast<int32_t>(roundf(std::numeric_limits<int32_t>::max() / (1 << bits))))
		std::cout << "\e[1;31mGiven value is greater than max representable value\e[0m" << std::endl;
	if (value < static_cast<int32_t>(roundf(std::numeric_limits<int32_t>::min() / (1 << bits))))
		std::cout << "\e[1;31mGiven value is lower than min representable value\e[0m" << std::endl;
	this->value = value * (1 << bits);
}

Fixed::Fixed(const float value)
{
	//	std::cout << "Float constructor called" << std::endl;
	if (value > std::numeric_limits<int32_t>::max() / (1 << bits))
		std::cout << "\e[1;31mGiven value exeeds max representable value\e[0m" << std::endl;
	if (value < std::numeric_limits<int32_t>::min() / (1 << bits))
		std::cout << "\e[1;31mGiven value is lower than min representable value\e[0m" << std::endl;
	this->value = roundf(value * ( 1 << bits));
}

Fixed::~Fixed()
{	//	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &a)
{
	//	std::cout << "Copy constructor called" << std::endl;
	*this = a;
}

Fixed& Fixed::operator=(const Fixed &a)
{
	//	std::cout << "Copy assignment operator called" << std::endl;
	this->value = a.getRawBits();
	return (*this);
}

Fixed& Fixed::operator+(const Fixed &a)
{
	//	std::cout << "Addition operator called" << std::endl;
	this->value += a.getRawBits();
	return (*this);
}

Fixed& Fixed::operator-(const Fixed &a)
{
	//	std::cout << "Subtraction operator called" << std::endl;
	this->value -= a.getRawBits();
	return (*this);
}

Fixed& Fixed::operator*(const Fixed &a)
{
	//	std::cout << "Multiplication operator called" << std::endl;
	this->value *= a.getRawBits() / (1 << 8);
	return (*this);
}

Fixed& Fixed::operator/(const Fixed &a)
{
	//	std::cout << "Division operator called" << std::endl;
	if (a.getRawBits() == 0)
		std::cout << "\e[1;31mDivision by 0, be careful!\e[0m" << std::endl;
	this->value = this->getRawBits() * (1 << 8) / a.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &o, const Fixed &a)
{
	o << a.toFloat();
	return (o);
}

int	Fixed::getRawBits( void ) const
{
	//	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits( int const raw )
{
	//	std::cout << "setRawBits member function called" << std::endl;
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

bool	operator<(Fixed a, Fixed b)
{
	if (a.getRawBits() < b.getRawBits())
		return (true);
	return (false);
}

bool	operator>(Fixed a, Fixed b)
{
	if (a.getRawBits() > b.getRawBits())
		return (true);
	return (false);
}

bool	operator>=(Fixed a, Fixed b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (true);
	return (false);
}

bool	operator<=(Fixed a, Fixed b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (true);
	return (false);
}

bool	operator==(Fixed a, Fixed b)
{
	if (a.getRawBits() == b.getRawBits())
		return (true);
	return (false);
}

bool	operator!=(Fixed a, Fixed b)
{
	if (a.getRawBits() != b.getRawBits())
		return (true);
	return (false);
}

Fixed	&Fixed::operator++(int)
{
	Fixed	&temp = *this;
	this->value += 1;
	return (temp);
}

Fixed	&Fixed::operator++()
{
	this->value += 1;
	return (*this);
}

Fixed	&Fixed::operator--(int)
{
	Fixed	&temp = *this;
	this->value -= 1;
	return (temp);
}

Fixed	&Fixed::operator--()
{
	this->value -= 1;
	return (*this);
}

Fixed&	Fixed::min( Fixed &a, Fixed &b )
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}
Fixed&	Fixed::max( Fixed &a, Fixed &b )
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}
const Fixed&	Fixed::min( const Fixed &a, const Fixed &b )
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}
const Fixed&	Fixed::max( const Fixed &a, const Fixed &b )
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}