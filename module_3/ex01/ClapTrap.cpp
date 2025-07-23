/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:30:41 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/23 18:22:02 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << WARN << "ClapTrap default constructor called" << RESET << std::endl;
	this->_name = "DEFAULT";
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attak_damage = 0;
}

ClapTrap::ClapTrap(const std::string name)
{
	std::cout << WARN << "ClapTrap " << name << " is constructed" << RESET << std::endl;
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attak_damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << WARN 
	<< "ClapTrap " << this->_name << " is destroyed"
	<< RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << WARN
	<< "ClapTrap " << other._name << " replicated" << RESET << std::endl;
	if (this != &other)
		*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << WARN << "ClapTrap assignment operator called" << RESET << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attak_damage = other._attak_damage;
	return (*this);
}

void	ClapTrap::attack( const std::string& target)
{
	std::cout << MAGENT
	<< "ClapTrap " << this->_name
	<< " attacs " << target
	<< ", causing " << this->_attak_damage
	<< " points of damage!"
	<< RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	// if (amount > static_cast<unsigned int>(this->_hit_points))
	// {
	// 	std::cout << RED << "ClapTrap " << this->_name
	// 	<< " is dead. RIP" << RESET << std::endl;
	// 	return ;
	// }
	this->_hit_points -= amount;
	std::cout << YELLOW
	<< "ClapTrap " << this->_name
	<< " takes " << amount
	<< " damage. (Current hit points: " << this->_hit_points << ")"
	<< RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_hit_points += amount;
	std::cout << GREEN
	<< "ClapTrap " << this->_name
	<< " repaired " << amount
	<< " hit points. (Current hit points: " << this->_hit_points << ")"
	<< RESET << std::endl;
}
