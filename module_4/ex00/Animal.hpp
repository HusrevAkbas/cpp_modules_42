/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:06:45 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/07 14:04:48 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ANIMAL_H
# define	ANIMAL_H

# include <iostream>

class	Animal
{
	protected:
		std::string	_type;
	public:
		Animal ();
		virtual ~Animal ();
		Animal( const std::string type );
		Animal( const Animal &other);
		Animal& operator=( const Animal &other);
		std::string	get_type( void );
		virtual void	make_sound( void );
};

#endif	//	ANIMAL_H