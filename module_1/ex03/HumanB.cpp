/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:20:55 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/16 15:27:00 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
	this->name = name;
	this->weapon = nullptr;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->weapon = &weapon;
}

void	HumanB::attack( void )
{
	std::cout	<< this->name << " attacks with their ";
	if (this->weapon)
		std::cout << this->weapon->getType() << std::endl;
	else
		std::cout << "bare hands!" << std::endl;
}