/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:56:26 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/23 18:18:08 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SCAVTRAP_H
# define	SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : private ClapTrap
{
	private:
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap( const std::string name);
		ScavTrap( const ScavTrap &other);
		ScavTrap& operator=( const ScavTrap &other );
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void guardGate();
};

#endif	//	SCAVTRAP_H