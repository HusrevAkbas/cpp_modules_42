/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:08:23 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 16:36:35 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << WARN << "Animal Default constructor" << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << WARN << "Animal Destructor" << RESET << std::endl;
}

Animal::Animal( const std::string type )
{
	std::cout << WARN << "Animal parameter constructor" << RESET << std::endl;
	this->_type = type;
}

Animal::Animal( const Animal &other)
{
	std::cout << WARN << "Animal copy" << RESET << std::endl;
	if (this != &other)
		*this = other;
}

Animal& Animal::operator=( const Animal &other )
{
	std::cout << WARN << "Animal assign" << RESET << std::endl;
	if (this == &other)
		return ( *this );
	this->_type = other._type;
	return ( *this );
}
void	Animal::make_sound( void )
{
	std::cout << MAGENT << "- This animal is quite quiet -" << RESET << std::endl;
}

std::string	Animal::get_type()
{	return (this->_type);	}