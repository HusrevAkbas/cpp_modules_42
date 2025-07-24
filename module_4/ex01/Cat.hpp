/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:06:45 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 15:12:26 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CAT_H
# define	CAT_H

# include <iostream>
# include "Animal.hpp"

class	Cat : public Animal
{
	private:
		Brain	*_brain;
	protected:
		std::string	_type;
	public:
		Cat ();
		~Cat ();
		Cat( const std::string type );
		Cat( const Cat &other);
		Cat& operator=( const Cat &other);
		std::string	get_type();
		void	make_sound( void );
};
#endif	//	CAT_H