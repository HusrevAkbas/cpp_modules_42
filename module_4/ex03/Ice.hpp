/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Icel.hpp                                         :+:      :+:    :+:   */
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

class	Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice( std::string const & type );
		Ice( const Ice& other);
		Ice& operator=( const Ice& other);
		Ice*	clone( void ) const;
		void	use( ICharacter& target );
};
