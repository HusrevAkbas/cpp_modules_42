/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:23:20 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/08 13:17:09 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	don( "Don" );
	FragTrap	son( "Son" );

	don.guardGate();
	son.highFivesGuys();

	son.attack( "Danny");
	don.attack("Yen");

	son.beRepaired(8);
	don.beRepaired(18);

	son.takeDamage(17);
	don.takeDamage(61);

	return (0);
}