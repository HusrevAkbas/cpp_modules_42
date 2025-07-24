/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:08:23 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 15:42:28 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {}

Animal::~Animal() {}

Animal::Animal( const std::string type )
{	this->_type = type;		}

Animal::Animal( const Animal &other)
{
	if (this != &other)
		*this = other;
}

Animal& Animal::operator=( const Animal &other )
{
	if (this == &other)
		return ( *this );
	this->_type = other._type;
	return ( *this );
}
void	Animal::make_sound( void )
{
	std::cout << "- This animal is quite quiet -" << std::endl;
}

std::string	Animal::get_type()
{	return (this->_type);	}