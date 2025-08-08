/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:08:23 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 15:16:23 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{	std::cout << WARN4 << "Brain default constructor" << RESET << std::endl;	}

Brain::~Brain()
{	std::cout << WARN4 << "Brain destructor" << RESET << std::endl;	}

Brain::Brain( const std::string ideas[100] )
{
	std::cout << WARN4 << "Brain parameter constructor" << RESET << std::endl;
	*this->_ideas = *ideas;
}

Brain::Brain( const Brain &other)
{
	std::cout << WARN4 << "Brain copy" << RESET << std::endl;
	if (this != &other)
		*this = other;
}

Brain& Brain::operator=( const Brain &other )
{
	std::cout << WARN4 << "Brain assign" << RESET << std::endl;
	if (this == &other)
		return ( *this );
	for (size_t i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	return ( *this );
}

std::string*	Brain::get_ideas ( void )
{	return (this->_ideas);	}
