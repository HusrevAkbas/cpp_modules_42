/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:53:48 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/27 22:25:35 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	POINT_H
# define	POINT_H

#include "Fixed.hpp"

class	Point
{
	private:
		Fixed	x;
		Fixed	y;
	public:
		Point();
		Point( float const x, float const y );
		Point( Point& p );
		Point&	operator=( const Point& p );
		~Point();
		Fixed	get_x() const;
		Fixed	get_y() const;
		void	set_x( Fixed x );
		void	set_y( Fixed y );
};

#endif	//	POINT_H