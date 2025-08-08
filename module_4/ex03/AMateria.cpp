/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMaterial.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:08:23 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 17:09:43 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria () :
	_type("UNDEFINED"), _equipped(false) {}

AMateria::AMateria( std::string const & type ) :
	_type(type), _equipped(false) {}

AMateria::~AMateria(){}

AMateria::AMateria( const AMateria& other) :
	_type(other._type), _equipped(other._equipped) {}

 std::string const & AMateria::getType( void) const
{	return (this->_type);	}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* shoots an AMateria at "
	<< target.getName() << " *" << std::endl;
}

bool	AMateria::isEquipped()
{ return (this->_equipped);	}

void	AMateria::setEquipped(bool status)
{ this->_equipped = status;	}
