/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:41 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:11:15 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	TRIANGLE_H
# define	TRIANGLE_H

# include <iostream>
# include "Point.hpp"

class Triangle
{
	private:
		Point	_points[3];
	public:
		Triangle();
		~Triangle();
		Triangle( Triangle const &t );
		Triangle( Point const &p1, Point const &p2, Point const &p3 );
		Triangle& operator=( const Triangle &a );
		Fixed	getDeterminant ();
		Fixed	getArea ();
};

#endif	//	TRIANGLE_H