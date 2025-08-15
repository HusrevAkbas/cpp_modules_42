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

Dog::Dog() : AAnimal ( "Dog" )
{
	std::cout << WARN3 << "Dog default constructor" << RESET << std::endl;
	this->_brain = new Brain();
};

Dog::~Dog()
{
	std::cout << WARN3 << "Dog destructor" << RESET << std::endl;
	delete (this->_brain);
}

Dog::Dog( const Dog &other) : AAnimal (other)
{
	this->_brain = NULL;
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
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*other._brain);
	return ( *this );
}

void	Dog::make_sound ()
{	std::cout << MAGENT << "WooF woOF" << RESET << std::endl;	}

Brain*	Dog::getBrain()
{	return (this->_brain);	}