/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:53:47 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/09/30 11:48:37 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point () : _x( 0 ), _y( 0 ) {}

Point::~Point(){}

Point::Point( float const x, float const y) : _x(x), _y(y) {}

Point::Point( Point& p) : _x(p.get_x()), _y(p.get_y()) {}

Point&	Point::operator=(const Point &p)
{
	(void) p;
	return (*this);
}

Fixed	Point::get_x() const
{	return (this->_x);	}

Fixed	Point::get_y() const
{	return (this->_y);	}

bool	operator==( const Point& a, const Point &b )
{
	return (a.get_x() == b.get_x() && a.get_y() == b.get_y());
}