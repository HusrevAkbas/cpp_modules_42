/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:41 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/05 14:34:22 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_H
# define	FIXED_H

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &a);
		Fixed& operator=(const Fixed &a);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif	//	FIXED_H