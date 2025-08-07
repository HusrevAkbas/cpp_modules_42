/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:30:41 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/07 20:55:21 by husrevakbas      ###   ########.fr       */
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
