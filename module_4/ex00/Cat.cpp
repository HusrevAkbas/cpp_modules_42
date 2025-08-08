/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:08:23 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 15:16:23 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal ( "Cat" ), _type("Cat")
{	std::cout << WARN2 << "Cat DEFAULT constructed" << RESET << std::endl;	};

Cat::~Cat()
{	std::cout << WARN2 << "Cat destructed" << RESET << std::endl;	}

Cat::Cat( const std::string type ) : Animal ( "Cat" ), _type("Cat")
{	std::cout << WARN2 << "Cat (arg:" << type << ") constructed" << RESET << std::endl;	}

Cat::Cat( const Cat &other)
{
	if (this != &other)
		*this = other;
}

Cat& Cat::operator=( const Cat &other )
{
	if (this == &other)
		return ( *this );
	this->_type = other._type;
	return ( *this );
}

std::string	Cat::get_type ()
{	return (this->_type);	}

void	Cat::make_sound ()
{	std::cout << "MEoW" << std::endl;	}