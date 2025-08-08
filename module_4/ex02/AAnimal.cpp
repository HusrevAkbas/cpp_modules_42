/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:08:23 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/07 17:30:43 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal () {}

AAnimal::AAnimal ( const AAnimal& other)
{
	if (this != &other)
		*this = other;
}

AAnimal::~AAnimal(){}

void	AAnimal::make_sound( void )
{
	std::cout << MAGENT << "- This animal is quite quiet -" << RESET << std::endl;
}
