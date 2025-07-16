/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:15:05 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/16 15:12:02 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA (std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	// this->name = name;
	// this->weapon = weapon;
}

void	HumanA::attack( void )
{
	std::cout	<< this->name << " attacks with their "
				<< this->weapon.getType() << std::endl;
}