/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:08:46 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/15 23:08:02 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{	this->name = name;	}

Zombie::~Zombie( void )
{	std::cout << this->name << std::endl;	}

void	Zombie::announce()
{	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;	}

void	Zombie::setName( std::string name )
{	this->name = name;	}
