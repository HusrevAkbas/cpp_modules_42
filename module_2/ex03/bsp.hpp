/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:04:01 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/05 17:04:43 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_H
# define BSP_H

# include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);
Fixed	get_determinant(Point const& a, Point const& b, Point const& c);
Fixed	area_of_triangle(Point const& a, Point const& b, Point const& c);
bool	is_on_same_line(Point const &a, Point const &b, Point const &c);

#endif