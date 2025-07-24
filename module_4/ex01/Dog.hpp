/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:06:45 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 15:12:26 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DOG_H
# define	DOG_H

# include <iostream>
# include "Animal.hpp"

class	Dog : public Animal
{
	private:
		Brain	*_brain;
	protected:
		std::string	_type;
	public:
		Dog ();
		~Dog ();
		Dog( const std::string type );
		Dog( const Dog &other);
		Dog& operator=( const Dog &other);
		std::string	get_type ( void );
		void	make_sound( void );
};

#endif	//	DOG_H