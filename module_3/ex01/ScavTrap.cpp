/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:02:19 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/23 18:25:04 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << WARN2 << "Default ScavTrap constructed" << RESET << std::endl;
	this->_name = "DEFAULT";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attak_damage = 20;
}

ScavTrap::ScavTrap( const std::string name)
{
	std::cout << WARN2 << "ScavTrap " << name << " is constructed" << RESET << std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attak_damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << WARN2 << "ScavTrap " << this->_name << " is destroyed" << RESET << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << MAGENT
	<< "ScavTrap " << this->_name
	<< " attacs " << target
	<< ", causing " << this->_attak_damage
	<< " points of damage!"
	<< RESET << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << BLUE
	<< "ScavTrap " << this->_name
	<< " switched to Gate keeper mode "
	<< RESET << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	// if (amount > static_cast<unsigned int>(this->_hit_points))
	// {
	// 	std::cout << RED << "ClapTrap " << this->_name
	// 	<< " is dead. RIP" << RESET << std::endl;
	// 	return ;
	// }
	this->_hit_points -= amount;
	std::cout << YELLOW
	<< "ScavTrap " << this->_name
	<< " takes " << amount
	<< " damage. (Current hit points: " << this->_hit_points << ")"
	<< RESET << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	this->_hit_points += amount;
	std::cout << GREEN
	<< "ScavTrap " << this->_name
	<< " repaired " << amount
	<< " hit points. (Current hit points: " << this->_hit_points << ")"
	<< RESET << std::endl;
}
