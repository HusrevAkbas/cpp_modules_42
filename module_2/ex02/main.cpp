/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:57:01 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/27 01:17:57 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed	a( 10 );
	Fixed	b( 42.241f );
	Fixed	c( b * a );
	Fixed	d( b );

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;

	std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;

	a = 0;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	a = 10;

	std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;

	std::cout << "a < b " << std::boolalpha << (a < b) << std::endl;
	std::cout << "a > b " << (a > b) << std::endl;

	std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;

	std::cout << "c == b " << (c == b) << std::endl;
	std::cout << "d == b " << (d == b) << std::endl;

	std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;

	std::cout << "d > b " << (d > b) << std::endl;
	std::cout << "d >= b " << (d >= b) << std::endl;
	std::cout << "d <= b " << (d <= b) << std::endl;

	std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;

	std::cout << "c > b " << (c > b) << std::endl;
	std::cout << "c >= b " << (c >= b) << std::endl;
	std::cout << "c <= b " << (c <= b) << std::endl;

	std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;

	d++;
	std::cout << "d++: " << d << std::endl;
	std::cout << "d > b " << (d > b) << std::endl;
	std::cout << "d >= b " << (d >= b) << std::endl;
	std::cout << "d <= b " << (d <= b) << std::endl;

	std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;

	d--;
	std::cout << "d--: " << d << std::endl;
	std::cout << "d > b " << (d > b) << std::endl;
	std::cout << "d >= b " << (d >= b) << std::endl;
	std::cout << "d <= b " << (d <= b) << std::endl;

	std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;

	d--;
	std::cout << "d--: " << d << std::endl;
	std::cout << "d > b " << (d > b) << std::endl;
	std::cout << "d >= b " << (d >= b) << std::endl;
	std::cout << "d <= b " << (d <= b) << std::endl;

	std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;

	std::cout << "a set to 0" << std::endl;
	a = 0;
	std::cout << "a: " << a << std::endl;
	a++;
	std::cout << "a++: " << a << std::endl;
	std::cout << "a set to 0" << std::endl;
	a = 0;
	std::cout << "a: " << a << std::endl;
	a--;
	std::cout << "a--: " << a << std::endl;

	std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;
	
	std::cout << "a and b set to 1000" << std::endl;
	a = 100;
	b = 100;
	a++;
	std::cout << "a == b " << (a == b) << std::endl;
	std::cout << "a: " << a.toFloat() << std::endl;
	std::cout << "b: " << b.toFloat() << std::endl;
	std::cout << "a (raw bits): " << a.getRawBits() << std::endl;
	std::cout << "b (raw bits): " << b.getRawBits() << std::endl;

	std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "max(a, b)" << Fixed::max(a, b) << std::endl;
	std::cout << "min(a, b)" << Fixed::min(a, b) << std::endl;
	std::cout << "max(c, d)" << Fixed::max(c, d) << std::endl;
	std::cout << "min(c, d)" << Fixed::min(c, d) << std::endl;

	return (0);
}
