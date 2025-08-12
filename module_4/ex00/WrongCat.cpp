/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:08:23 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 15:16:23 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal ( "WrongCat" ) {}

WrongCat::~WrongCat(){}

WrongCat::WrongCat( const WrongCat &other)
{
	if (this != &other)
		*this = other;
}

WrongCat& WrongCat::operator=( const WrongCat &other )
{
	if (this == &other)
		return ( *this );
	this->_type = other._type;
	return ( *this );
}

void	WrongCat::make_sound ()
{	std::cout << "MEoW" << std::endl;	}