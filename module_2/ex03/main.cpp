/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:52:32 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/06 13:27:21 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

int	main()
{
	Point	a(0, 0);
	Point	b(3, 0);
	Point	c(0, 4);
	Point	p1(1, 1);

	std::cout << "is point in triangle: " << std::boolalpha << bsp(a, b, c, p1) << std::endl;

	Point	d(10, 10);
	Point	e(10, 14);
	Point	f(15, 10);
	Point	p2(13, 15);

	std::cout << "is point in triangle: " << std::boolalpha << bsp(d, e, f, p2) << std::endl;

	Point	g(0, 1);
	Point	h(1, 0);
	Point	i(0, 0);
	Point	p3(0.495, 0.495);

	std::cout << "is point in triangle: " << std::boolalpha << bsp(g, h, i, p3) << std::endl;	a = Point(10, 10);

	return (0);
}
