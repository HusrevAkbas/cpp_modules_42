/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:12:36 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/08 16:06:09 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <typeinfo>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_library[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource& other);
		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const & type);
};

