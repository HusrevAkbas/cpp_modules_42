/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:06:45 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 15:12:26 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WRONG_CAT_H
# define	WRONG_CAT_H

# include <iostream>
# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongCat ();
		~WrongCat ();
		WrongCat( const std::string type );
		WrongCat( const WrongCat &other);
		WrongCat& operator=( const WrongCat &other);
		std::string	get_type();
		void	make_sound( void );
};

#endif	//	WRONG_CAT_H