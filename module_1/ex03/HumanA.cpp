/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:15:05 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:12:28 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA (std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	// this->name = name;
	// this->weapon = weapon;
}

void	HumanA::attack( void )
{
	std::cout	<< this->_name << " attacks with their "
				<< this->_weapon.getType() << std::endl;
}