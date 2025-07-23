/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:41 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:59:44 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_H
# define	FIXED_H

#include <limits.h>
#include <cmath>
#include <iostream>
#include <iomanip>

class Fixed
{
	private:
		int					_value;
		static const int	bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &a);
		Fixed(const int value);
		Fixed(const float value);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt ( void ) const;
		Fixed&	operator=(const Fixed &a);
		Fixed	operator+(const Fixed &a);
		Fixed	operator-(const Fixed &a);
		Fixed	operator*(const Fixed &a);
		Fixed	operator/(const Fixed &a);
		Fixed&	operator++(int);
		Fixed&	operator++();
		Fixed&	operator--(int);
		Fixed&	operator--();
		static Fixed&	min(Fixed &a, Fixed &b);
		static Fixed&	max(Fixed &a, Fixed &b);
		static const Fixed&	min(const Fixed &a, const Fixed &b);
		static const Fixed&	max(const Fixed &a, const Fixed &b);
	};
bool	operator<(Fixed a, Fixed b);
bool	operator>(Fixed a, Fixed b);
bool	operator>=(Fixed a, Fixed b);
bool	operator<=(Fixed a, Fixed b);
bool	operator==(Fixed a, Fixed b);
bool	operator!=(Fixed a, Fixed b);
std::ostream& operator<<(std::ostream &o, const Fixed &a);

#endif	//	FIXED_H