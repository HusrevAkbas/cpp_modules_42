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

Cat::Cat() : AAnimal ( "Cat" )
{	
	std::cout << WARN2 << "Cat default constructor" << RESET << std::endl;
	this->_brain = new Brain();
};

Cat::~Cat()
{
	std::cout << WARN2 << "Cat destructor" << RESET << std::endl;
	delete (this->_brain);
}

Cat::Cat( const Cat &other)
{
	this->_brain = NULL;
	std::cout << WARN2 << "Cat copy" << RESET << std::endl;
	if (this != &other)
		*this = other;
}

Cat& Cat::operator=( const Cat &other )
{
	std::cout << WARN2 << "Cat assign" << RESET << std::endl;
	if (this == &other)
		return ( *this );
	this->_type = other._type;
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*other._brain);
	return ( *this );
}

void	Cat::make_sound ()
{	std::cout << MAGENT << "MEoW" << RESET << std::endl;	}

Brain*	Cat::getBrain()
{	return (this->_brain);	}