/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Curel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:08:23 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 17:09:43 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria ("cure") {}

Cure::~Cure() {}

Cure::Cure( std::string const & type ) : AMateria ("cure")
{	(void) type;	}

Cure::Cure( const Cure& other) : AMateria ("cure")
{
	if (this != &other)
		*this = other;
}

Cure&	Cure::operator=( const Cure& other)
{
	if (this == &other)
		return (*this);
	this->_type = other.getType();
	return (*this);
}

Cure*	Cure::clone( void ) const
{
	Cure	*new_one = new Cure( "cure");
	*new_one = *this;
	return (new_one);
}

void	Cure::use( ICharacter& target )
{
	std::cout << this->getType() << ": * shoots an ice bolt at "
	<< target.getName() << std::endl;
}