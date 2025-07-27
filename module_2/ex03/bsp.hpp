/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:04:01 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/27 22:21:39 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_H
# define BSP_H

# include "Point.hpp"
# include "Triangle.hpp"

# define	EPSYLON	(Fixed(0))++

bool	bsp(Point const a, Point const b, Point const c, Point const point);
// Fixed	get_determinant(Point const& a, Point const& b, Point const& c);
// Fixed	area_of_triangle(Point const& a, Point const& b, Point const& c);

#endif