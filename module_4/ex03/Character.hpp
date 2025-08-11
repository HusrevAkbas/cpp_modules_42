/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Characterl.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:06:45 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 17:09:02 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class	Character : virtual public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_materia[4];
	public:
		Character();
		~Character();
		Character( std::string const & name );
		Character( const Character& other);
		Character& operator=( const Character& other);
		std::string const & getName() const;
		void	equip( AMateria *m );
		void	unequip( int idx );
		void	use( int idx, ICharacter &target);
};
