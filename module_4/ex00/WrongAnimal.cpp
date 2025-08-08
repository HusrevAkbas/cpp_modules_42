/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:08:23 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 15:42:28 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {}

WrongAnimal::~WrongAnimal() {}

WrongAnimal::WrongAnimal( const std::string type )
{	this->_type = type;		}

WrongAnimal::WrongAnimal( const WrongAnimal &other)
{
	if (this != &other)
		*this = other;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal &other )
{
	if (this == &other)
		return ( *this );
	this->_type = other._type;
	return ( *this );
}
void	WrongAnimal::make_sound( void )
{
	std::cout << "- This animal makes wrong noise -" << std::endl;
}

std::string	WrongAnimal::get_type(){	return (this->_type);	}