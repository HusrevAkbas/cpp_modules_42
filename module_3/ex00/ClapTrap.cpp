/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:30:41 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/23 16:27:09 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << WARN << "Default constructor called" << RESET << std::endl;
	this->_name = "USE PARAMETERIZED CONSTRUCTOR!";
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attak_damage = 0;
}

ClapTrap::ClapTrap(const std::string name)
{
	std::cout << WARN << "Constructor with parameter called" << RESET << std::endl;
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attak_damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << WARN << "Destructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << WARN << "Copy constructor called" << RESET << std::endl;
	if (this != &other)
		*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << WARN << "Assignment operator called" << RESET << std::endl;
	if (this != &other)
		*this = other;
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
	if (amount > static_cast<unsigned int>(this->_hit_points))
	{
		std::cout << RED << "ClapTrap " << this->_name
		<< " is dead. RIP" << RESET << std::endl;
		return ;
	}
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
