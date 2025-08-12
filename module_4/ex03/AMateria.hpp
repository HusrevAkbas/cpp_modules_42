/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMaterial.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:06:45 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 17:09:02 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ICharacter.hpp"

class	AMateria
{
	protected:
		std::string	_type;
		bool		_equipped;
	public:
		AMateria();
		AMateria( std::string const & type );
		AMateria( const AMateria& other );
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();
		std::string const & getType( void) const;
		virtual AMateria* clone( void ) const = 0;
		virtual void	use( ICharacter& target );
		bool	isEquipped();
		void	setEquipped(bool status);
};
