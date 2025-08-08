/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:08:23 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 15:16:23 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal ( "Dog" ), _type("Dog")
{	std::cout << WARN3 << "Dog DEFAULT constructed" << RESET << std::endl;	};

Dog::~Dog()
{	std::cout << WARN3 << "Dog destructed" << RESET << std::endl;	}

Dog::Dog( const std::string type ) : Animal ("Dog"), _type("Dog")
{	std::cout << WARN3 << "Dog (arg:" << type << ") constructed" << RESET << std::endl;		}

Dog::Dog( const Dog &other)
{
	if (this != &other)
		*this = other;
}

Dog& Dog::operator=( const Dog &other )
{
	if (this == &other)
		return ( *this );
	this->_type = other._type;
	return ( *this );
}

std::string	Dog::get_type ( void )
{	return (this->_type);	}

void	Dog::make_sound ()
{	std::cout << "WooF woOF" << std::endl;	}