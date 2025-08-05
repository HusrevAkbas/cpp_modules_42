/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:53:48 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/05 16:22:23 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	POINT_H
# define	POINT_H

#include "Fixed.hpp"

class	Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		Point();
		Point( float const x, float const y );
		Point( Point& p );
		Point&	operator=( const Point& p );
		~Point();
		Fixed	get_x() const;
		Fixed	get_y() const;
};

#endif	//	POINT_H