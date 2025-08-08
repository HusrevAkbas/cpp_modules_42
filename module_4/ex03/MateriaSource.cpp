/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:12:36 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/08 16:08:11 by huakbas          ###   ########.fr       */
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

void MateriaSource::learnMateria(AMateria* matearia)
{
	if (!matearia)
	{
		std::cout << "I don't learn with NULL pointers" << std::endl;
		return ;
	}
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->_library[i])
		{
			std::cout << matearia->getType() << " learned" << std::endl;
			this->_library[i] = matearia;
			return ;
		}
	}
	std::cout << "All learning slots are full" << std::endl;
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