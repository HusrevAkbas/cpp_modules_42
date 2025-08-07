/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:25:53 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/23 21:55:25 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DIAMONDTRAP_H
# define	DIAMONDTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap &operator=( const DiamondTrap &other );
		using ScavTrap::attack;
		void	whoAmI( void );
};

#endif //DIAMONDTRAP_H