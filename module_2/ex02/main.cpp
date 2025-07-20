/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:57:01 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/20 22:58:52 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed a;
	Fixed const b( 100 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	a = Fixed( 10.600f );
	a = a + b;
	a = a / b;
	std::cout << std::endl;
	std::cout << "a -eq b " << (a == b) << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << std::endl;
	Fixed aa;
	Fixed const ba( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << aa << std::endl;
	std::cout << ++aa << std::endl;
	std::cout << aa << std::endl;
	// std::cout << aa++ << std::endl;
	std::cout << aa << std::endl;
	std::cout << ba << std::endl;
	std::cout << Fixed::max( aa, ba ) << std::endl;
	std::cout << Fixed::min( b, c ) << std::endl;
	std::cout << Fixed(12) / 2 << std::endl;
	std::cout << Fixed(12) * 2 << std::endl;
	return (0);
}
