/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:30:41 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/07 11:51:13 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("DEFAULT")
{
	std::cout << WARN3 << "FragTrap default constructor called" << RESET << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attak_damage = 30;
}

FragTrap::FragTrap( const std::string name ) : ClapTrap( name )
{
	std::cout << WARN3 << "FragTrap " << name << " is constructed" << RESET << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attak_damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << WARN3 
	<< "FragTrap " << this->_name << " is destroyed"
	<< RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << WARN3
	<< "FragTrap " << other._name << " replicated" << RESET << std::endl;
	if (this != &other)
		*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << WARN3 << "FragTrap assignment operator called" << RESET << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attak_damage = other._attak_damage;
	return (*this);
}

void	FragTrap::attack( const std::string& target)
{
	if (this->_hit_points <= 0)
	{
		std::cout << MAGENT << "FragTrap " << this->_name
		<< " is already dead. Can't attack. \\( X _ X )/" << RESET << std::endl;
		return ;
	}
	if (this->_energy_points <= 0)
	{
		std::cout << MAGENT << "FragTrap " << this->_name
		<< " doesn't have any energy. Can't attack. /( @ _ @ )\\" << RESET << std::endl;
		return ;
	}
	this->_energy_points--;
	std::cout << MAGENT
	<< "FragTrap " << this->_name
	<< " attacks " << target
	<< ", causing " << this->_attak_damage
	<< " points of damage!"
	<< RESET << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << YELLOW << "FragTrap " << this->_name
		<< " is already dead. You can't hurt it anymore." << RESET << std::endl;
		return ;
	}
	this->_hit_points -= amount;
	std::cout << YELLOW
	<< "FragTrap " << this->_name
	<< " takes " << amount
	<< " damage. (Current hit points: " << this->_hit_points << ")"
	<< RESET << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << GREEN << "FragTrap " << this->_name
		<< " is already dead. It can not be repaired. \\( X _ X )/" << RESET << std::endl;
		return ;
	}
	if (this->_energy_points <= 0)
	{
		std::cout << GREEN << "FragTrap " << this->_name
		<< " does'nt have any energy. It can not be repaired. /( @ _ @ )\\ " << RESET << std::endl;
		return ;
	}
	this->_energy_points--;
	this->_hit_points += amount;
	std::cout << GREEN
	<< "FragTrap " << this->_name
	<< " repaired " << amount
	<< " hit points. (Current hit points: " << this->_hit_points << ")"
	<< RESET << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	if (this->_energy_points <= 0)
	{
		std::cout << GREEN << "FragTrap " << this->_name
		<< " does'nt have any energy. No High Fives. /( @ _ @ )\\ " << RESET << std::endl;
		return ;
	}
	this->_energy_points--;
	std::cout << GRAY
	<< "FragTrap " << this->_name
	<< " high fives "
	<< RESET << std::endl;
}
