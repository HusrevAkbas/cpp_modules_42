/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:52:32 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/05 17:26:43 by huakbas          ###   ########.fr       */
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
	Point	p2(13, 11);

	std::cout << "is point in triangle: " << std::boolalpha << bsp(d, e, f, p2) << std::endl;

	Point	g(1, 1);
	Point	h(2, 2);
	Point	i(3, 1);
	Point	p3(3, 3);

	std::cout << "is point in triangle: " << std::boolalpha << bsp(g, h, i, p3) << std::endl;	a = Point(10, 10);

	return (0);
}
