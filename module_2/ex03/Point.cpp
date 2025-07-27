/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:53:47 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/27 22:25:45 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point ()
{
	this->x = 0;
	this->y = 0;
}

Point::~Point(){}

Point::Point( float const x, float const y)
{
	this->x = Fixed(x);
	this->y = Fixed(y);
}

Point::Point( Point& p)
{
	this->x = p.x;
	this->y = p.y;
}

Point&	Point::operator=(const Point &p)
{
	this->x = p.x;
	this->y = p.y;
	return (*this);
}

Fixed	Point::get_x() const
{
	return (this->x);
}

Fixed	Point::get_y() const
{
	return (this->y);
}

void	Point::set_x( Fixed x )
{
	this->x = x;
}

void	Point::set_y( Fixed y )
{
	this->y = y;
}