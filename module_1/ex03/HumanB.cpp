/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:20:55 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/04 12:48:04 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::~HumanB () {}

HumanB::HumanB( std::string name )
{
	this->_name = name;
	this->_weapon = NULL;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->_weapon = &weapon;
}

void	HumanB::attack( void )
{
	std::cout	<< this->_name << " attacks with their ";
	if (this->_weapon)
		std::cout << this->_weapon->getType() << std::endl;
	else
		std::cout << "bare hands!" << std::endl;
}