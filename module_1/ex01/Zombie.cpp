/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:08:46 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/22 19:33:17 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{	this->_name = name;	}

Zombie::~Zombie( void )
{	std::cout << this->_name << std::endl;	}

void	Zombie::announce()
{	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;	}

void	Zombie::setName( std::string name )
{	this->_name = name;	}
