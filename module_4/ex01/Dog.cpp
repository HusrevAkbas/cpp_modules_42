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

Dog::Dog() : Animal ( "Dog" )
{
	std::cout << WARN3 << "Dog default constructor" << RESET << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
};

Dog::~Dog()
{
	std::cout << WARN3 << "Dog destructor" << RESET << std::endl;
	delete (this->_brain);
}

Dog::Dog( const Dog &other)
{
	std::cout << WARN3 << "Dog copy" << RESET << std::endl;
	if (this != &other)
		*this = other;
}

Dog& Dog::operator=( const Dog &other )
{
	std::cout << WARN3 << "Dog assign" << RESET << std::endl;
	if (this == &other)
		return ( *this );
	this->_type = other._type;
	this->_brain = other._brain;
	return ( *this );
}

std::string	Dog::get_type ( void )
{	return (this->_type);	}

void	Dog::make_sound ()
{	std::cout << MAGENT << "WooF woOF" << RESET << std::endl;	}

Brain*	Dog::getBrain()
{	return (this->_brain);	}