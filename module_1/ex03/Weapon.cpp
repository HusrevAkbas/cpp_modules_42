/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:03:31 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:11:50 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon ( std::string type )
{	this->_type = type;	}

const std::string	&Weapon::getType( void )
{	return	(this->_type);	}

void	Weapon::setType( std::string type )
{	this->_type = type;	}
