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

Cat::Cat()
{	
	std::cout << WARN2 << "Cat default constructor" << RESET << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
};

Cat::~Cat()
{
	std::cout << WARN2 << "Cat destructor" << RESET << std::endl;
	delete (this->_brain);
}

Cat::Cat( const Cat &other)
{
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
	this->_brain = new Brain(*other._brain);
	return ( *this );
}

std::string	Cat::get_type ()
{	return (this->_type);	}

void	Cat::make_sound ()
{	std::cout << MAGENT << "MEoW" << RESET << std::endl;	}

std::string	Cat::getIdea(int index)
{
	return (this->_brain->get_ideas()[index]);
}
void	Cat::setIdea(int index, std::string idea)
{
	this->_brain->get_ideas()[index] = idea;
}