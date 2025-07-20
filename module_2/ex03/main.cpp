/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:52:32 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/20 22:51:56 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

int	main()
{
	Point	a(0, 0);
	Point	b(3, 0);
	Point	c(0, 4);
	Point	point(1, 1);

	Fixed	f = Fixed(123);

	// std::cout << "area: " << area_of_triangle(a, b, c) << std::endl;
	std::cout << "is point in tri: " << bsp(a, b, c, point) << std::endl;

	a = Point(10, 10);
	b = Point(10, 14);
	c = Point(13, 10);
	point = Point(11, 11);
	std::cout << "is point in tri: " << bsp(a, b, c, point) << std::endl;

	a = Point(10, 10);
	b = Point(10, 14);
	c = Point(13, 10);
	point = Point(9, 9);
	std::cout << "is point in tri: " << bsp(a, b, c, point) << std::endl;
	return (0);
}
