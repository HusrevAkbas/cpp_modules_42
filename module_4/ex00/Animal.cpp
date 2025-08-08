/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:08:23 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/08 13:49:36 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() 
{	std::cout << WARN << "Animal DEFAULT constructed" << RESET << std::endl;	}

Animal::~Animal()
{	std::cout << WARN << "Animal " << this->get_type() << " destructed" << RESET << std::endl;	}

Animal::Animal( const std::string type ) : _type(type)
{	std::cout << WARN << "Animal " << type << " constructed" << RESET << std::endl;	}

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