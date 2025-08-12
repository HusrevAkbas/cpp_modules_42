/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:12:36 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/12 16:46:26 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource ()
{
	for (size_t i = 0; i < 4; i++)
		this->_library[i] = NULL;
}

MateriaSource::~MateriaSource ()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_library[i])
			delete this->_library[i];
	}
}

MateriaSource::MateriaSource (const MateriaSource& other)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (other._library[i])
			this->_library[i] = other._library[i]->clone();
		else
			this->_library[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_library[i])
			delete this->_library[i];
		if (other._library[i])
			this->_library[i] = other._library[i]->clone();
		else
			this->_library[i] = NULL;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
	{
		std::cout << RED << "I don't learn with NULL pointers" << RESET << std::endl;
		return ;
	}
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->_library[i])
		{
			std::cout << GRAY << materia->getType() << " learned" << RESET << std::endl;
			this->_library[i] = materia;
			return ;
		}
	}
	std::cout << RED << "All learning slots are full" << RESET << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_library[i] && this->_library[i]->getType() == type)
			return (this->_library[i]->clone());
	}
	return (NULL);
}
