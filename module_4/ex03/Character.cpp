/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Characterl.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:08:23 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 17:09:43 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
	Note: C++ compiler implicitly creates a copy constructor and overloads
	assignment operator in order to perform shallow copy at compile time.
*/

Character::Character() : _name("DEFAULT")
{
	for (size_t i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
	}
}

Character::Character( std::string const & name ) : _name(name)
{
	for (size_t i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

Character::Character( const Character& other) : _name(other._name)
{
	for (size_t i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	*this = other;
}

Character&	Character::operator=( const Character& other)
{
	if (this == &other)
		return (*this);
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
		this->_materia[i] = NULL;
	}
	this->_name = other.getName();
	for (size_t i = 0; i < 4; i++)
	{
		if (other._materia[i])
			this->_materia[i] = other._materia[i]->clone();
	}
	return (*this);
}

std::string const & Character::getName() const
{	return (this->_name);	}

void	Character::equip( AMateria *m )
{
	if (!m)
	{
		std::cout << "NULL can't be equipped" << std::endl;
		return ;
	}
	if (m->isEquipped())
	{
		std::cout << m->getType() << " is already equipped by someone" << std::endl;
		return ;
	}
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->_materia[i])
		{
			m->setEquipped(true);
			std::cout << this->_name << " equipped " << m->getType() << std::endl;
			this->_materia[i] = m;
			return ;
		}
	}
	std::cout << this->_name << " all materia slots are occupied" << std::endl;
}
void	Character::unequip( int idx )
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "Index is out of limits" << std::endl;
		return ;
	}
	if (this->_materia[idx])
	{
		this->_materia[idx]->setEquipped(false);
		this->_materia[idx] = NULL;
	}
}
void	Character::use( int idx, ICharacter &target)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "Index is out of limits" << std::endl;
		return ;
	}
	if (this->_materia[idx])
		this->_materia[idx]->use(target);
}
