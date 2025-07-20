/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:05:33 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/20 22:52:16 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	area_a_b_c;
	Fixed	area_a_b_point;
	Fixed	area_b_c_point;
	Fixed	area_a_c_point;
	Fixed	diff;

	area_a_b_c = area_of_triangle( a, b, c);
	area_a_b_point = area_of_triangle( a, b, point);
	area_b_c_point = area_of_triangle( b, c, point);
	area_a_c_point = area_of_triangle( a, c, point);

	diff = area_a_b_c - ( area_a_b_point + area_a_c_point + area_b_c_point);

	if (diff == 0 || (diff > 0 && diff < EPSYLON)
		|| (diff < 0 && diff > EPSYLON * -1))
		return (true);

	return (false);
}

Fixed	get_determinant( Point const& a, Point const& b, Point const& c )
{
	Fixed	det;

	det = a.get_x() * ( b.get_y() - c.get_y())
		+ b.get_x() * (c.get_y() - a.get_y())
		+ c.get_x() * (a.get_y() - b.get_y());
	return	(det);
}

Fixed	area_of_triangle( Point const& a, Point const& b, Point const& c )
{
	Fixed	det;

	det = get_determinant(a, b, c);
	if (det < Fixed(0))
		det = det * -1;
	return (det / 2);
}
