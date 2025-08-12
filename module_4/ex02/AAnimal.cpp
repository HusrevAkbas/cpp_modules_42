/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:08:23 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/12 15:46:01 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal () : _type("DEFAULT")
{
	std::cout << WARN << "AAnimal constructor" << RESET << std::endl;
}

AAnimal::AAnimal ( const std::string type) : _type(type)
{
	std::cout << WARN << "AAnimal parameterized constructor" << RESET << std::endl;
}

AAnimal::AAnimal ( const AAnimal& other)
{
	if (this != &other)
		*this = other;
}

AAnimal::~AAnimal()
{
	std::cout << WARN << "AAnimal destructor" << RESET << std::endl;
}

AAnimal& AAnimal::operator=( const AAnimal &other)
{
	if (this == &other)
	*this = other;
	return (*this);
}

// void	AAnimal::make_sound( void )
// {
// 	std::cout << MAGENT << "- This animal is quite quiet -" << RESET << std::endl;
// }
