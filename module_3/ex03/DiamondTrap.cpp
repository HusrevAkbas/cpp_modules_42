/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:30:41 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/23 18:22:02 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("DEFAULT_clap_name"), FragTrap ("DEFAULT_clap_name"), ScavTrap("DEFAULT_clap_name")
{
	std::cout << WARN << "DiamondTrap default constructor called" << RESET << std::endl;
	this->_name = "DEFAULT";
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attak_damage = 0;
}

DiamondTrap::DiamondTrap(const std::string name)
	: ScavTrap(name + "_clap_name")
{
	std::cout << WARN << "DiamondTrap " << name << " is constructed" << RESET << std::endl;
	this->_name = name;
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attak_damage = FragTrap::_attak_damage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << WARN 
	<< "DiamondTrap " << this->_name << " is destroyed"
	<< RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), FragTrap (other), ScavTrap (other)
{
	std::cout << WARN
	<< "DiamondTrap " << other._name << " replicated" << RESET << std::endl;
	if (this != &other)
		*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << WARN << "DiamondTrap assignment operator called" << RESET << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attak_damage = other._attak_damage;
	return (*this);
}

void	DiamondTrap::attack( const std::string& target) // : ScavTrap::attack(target)
{
	ScavTrap::attack(target);
	// std::cout << MAGENT
	// << "DiamondTrap " << this->_name
	// << " attacs " << target
	// << ", causing " << this->_attak_damage
	// << " points of damage!"
	// << RESET << std::endl;
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	// if (amount > static_cast<unsigned int>(this->_hit_points))
	// {
	// 	std::cout << RED << "DiamondTrap " << this->_name
	// 	<< " is dead. RIP" << RESET << std::endl;
	// 	return ;
	// }
	this->_hit_points -= amount;
	std::cout << YELLOW
	<< "DiamondTrap " << this->_name
	<< " takes " << amount
	<< " damage. (Current hit points: " << this->_hit_points << ")"
	<< RESET << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	this->_hit_points += amount;
	std::cout << GREEN
	<< "DiamondTrap " << this->_name
	<< " repaired " << amount
	<< " hit points. (Current hit points: " << this->_hit_points << ")"
	<< RESET << std::endl;
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << GRAY << "My name is DiamondTrap " << this->_name
	<< " but maybe you know me as " << ClapTrap::_name
	<< RESET<< std::endl;
}