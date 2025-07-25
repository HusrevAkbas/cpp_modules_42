/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Icel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:08:23 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 17:09:43 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria ("ice") {}

Ice::~Ice() {}

Ice::Ice( std::string const & type ) : AMateria ("ice")
{	(void) type;	}

Ice::Ice( const Ice& other) : AMateria ("ice")
{
	if (this != &other)
		*this = other;
}

Ice&	Ice::operator=( const Ice& other)
{
	if (this == &other)
		return (*this);
	this->_type = other.getType();
	return (*this);
}

Ice*	Ice::clone( void ) const
{
	Ice	*new_one = new Ice( "ice ");
	*new_one = *this;
	return (new_one);
}

void	Ice::use( ICharacter& target )
{
	std::cout << this->getType() << ": * shoots an ice bolt at "
	<< target.getName() << std::endl;
}