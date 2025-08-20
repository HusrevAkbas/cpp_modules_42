/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:56:45 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/20 11:08:58 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main()
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	char e = 'A';
	char f = 'a';
	::swap( e, f );
	std::cout << "a = " << e << ", b = " << f << std::endl;
	std::cout << "min( a, b ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( e, f ) << std::endl;

	float g = 12.42f;
	float h = 12.24f;
	::swap( g, h );
	std::cout << "a = " << g << ", b = " << h << std::endl;
	std::cout << "min( a, b ) = " << ::min( g, h ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( g, h ) << std::endl;


	return (0);
}