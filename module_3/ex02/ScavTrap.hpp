/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:56:26 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/07 20:51:05 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SCAVTRAP_H
# define	SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap( const std::string name);
		ScavTrap( const ScavTrap &other);
		ScavTrap& operator=( const ScavTrap &other );
		void attack(const std::string &target);
		void guardGate();
};

#endif	//	SCAVTRAP_H