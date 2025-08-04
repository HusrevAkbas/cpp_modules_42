/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:08:46 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/04 12:27:14 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << GREEN << this->_name + " constructed!" << RESET << std::endl;
}

Zombie::~Zombie( void )
{	std::cout << RED << this->_name + " destroyed!" << RESET << std::endl;	}

void	Zombie::announce()
{	std::cout << MAGENT << this->_name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;	}
