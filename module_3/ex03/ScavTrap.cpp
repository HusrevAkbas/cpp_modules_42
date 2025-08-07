/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:02:19 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/07 00:29:24 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("DEFAULT")
{
	std::cout << WARN2 << "Default ScavTrap constructed" << RESET << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attak_damage = 20;
}

ScavTrap::ScavTrap( const std::string name) : ClapTrap(name)
{
	std::cout << WARN2 << "ScavTrap " << name << " is constructed" << RESET << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attak_damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << WARN2 << "ScavTrap " << this->_name << " is destroyed" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << WARN
	<< "ScavTrap " << other._name << " replicated" << RESET << std::endl;
	if (this != &other)
		*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << WARN << "Assignment operator called" << RESET << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attak_damage = other._attak_damage;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hit_points <= 0)
	{
		std::cout << MAGENT << "ScavTrap " << this->_name
		<< " is already dead. Can't attack. \\( X _ X )/" << RESET << std::endl;
		return ;
	}
	if (this->_energy_points <= 0)
	{
		std::cout << MAGENT << "ScavTrap " << this->_name
		<< " doesn't have any energy. Can't attack. /( @ _ @ )\\" << RESET << std::endl;
		return ;
	}
	this->_energy_points--;
	std::cout << MAGENT
	<< "ScavTrap " << this->_name
	<< " attacks " << target
	<< ", causing " << this->_attak_damage
	<< " points of damage!"
	<< RESET << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_energy_points <= 0)
	{
		std::cout << MAGENT << "ScavTrap " << this->_name
		<< " doesn't have any energy. Can't switch to Gate Keeper mode. /( @ _ @ )\\" << RESET << std::endl;
		return ;
	}
	this->_energy_points--;
	std::cout << BLUE
	<< "ScavTrap " << this->_name
	<< " switched to Gate Keeper mode "
	<< RESET << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << YELLOW << "ScavTrap " << this->_name
		<< " is already dead. You can't hurt it anymore." << RESET << std::endl;
		return ;
	}
	this->_hit_points -= amount;
	std::cout << YELLOW
	<< "ScavTrap " << this->_name
	<< " takes " << amount
	<< " damage. (Current hit points: " << this->_hit_points << ")"
	<< RESET << std::endl;
	if (this->_hit_points <= 0)
	{
		std::cout << YELLOW << "ScavTrap " << this->_name
		<< " is no more. \\( X _ X )/" << RESET << std::endl;
		return ;
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << GREEN << "ScavTrap " << this->_name
		<< " is already dead. It can not be repaired. \\( X _ X )/" << RESET << std::endl;
		return ;
	}
	if (this->_energy_points <= 0)
	{
		std::cout << GREEN << "ScavTrap " << this->_name
		<< " does'nt have any energy. It can not be repaired. /( @ _ @ )\\ " << RESET << std::endl;
		return ;
	}
	this->_energy_points--;
	this->_hit_points += amount;
	std::cout << GREEN
	<< "ScavTrap " << this->_name
	<< " repaired " << amount
	<< " hit points. (Current hit points: " << this->_hit_points << ")"
	<< RESET << std::endl;
}
