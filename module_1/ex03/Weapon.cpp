/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:03:31 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/16 14:58:14 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon ( std::string type )
{	this->type = type;	}

const std::string	&Weapon::getType( void )
{	return	(this->type);	}

void	Weapon::setType( std::string type )
{	this->type = type;	}
