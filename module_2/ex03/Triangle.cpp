/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:36 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:18:58 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Triangle.hpp"

Triangle::Triangle()
{
	this->_points[0] = Point();
	this->_points[1] = Point();
	this->_points[2] = Point();
}

Triangle::~Triangle(){}

Triangle::Triangle(Point const &p1, Point const &p2, Point const &p3)
{
	this->_points[0] = p1;
	this->_points[1] = p2;
	this->_points[2] = p3;
}

Triangle::Triangle( Triangle const &t)
{
	if (this != &t)
		*this = t;
}

Triangle& Triangle::operator=(const Triangle &a)
{
	this->_points[0] = a._points[0];
	this->_points[1] = a._points[1];
	this->_points[2] = a._points[2];
	return (*this);
}

Fixed	Triangle::getDeterminant()
{
	Fixed	det;

	det = ( this->_points[0].get_x() * ( this->_points[1].get_y() - this->_points[2].get_y() ))
		+ ( this->_points[1].get_x() * ( this->_points[2].get_y() -  this->_points[0].get_y() ))
		+ ( this->_points[2].get_x() * ( this->_points[0].get_y() - this->_points[1].get_y() ));

	return	(det);
}

Fixed	Triangle::getArea()
{
	Fixed	det;

	det = this->getDeterminant();
	if (det < 0)
		det = det * -1;
	return (det / 2);
}
