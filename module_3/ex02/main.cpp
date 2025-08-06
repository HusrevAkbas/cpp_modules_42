/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:23:20 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/06 23:14:46 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	ron( "Ron" );
	ScavTrap	don( "Don" );
	FragTrap	son( "Son" );

	don.guardGate();
	son.highFivesGuys();

	son.attack( "Danny");
	don.attack("Yen");
	ron.attack("Saun");

	son.beRepaired(8);
	don.beRepaired(18);
	ron.beRepaired(28);

	son.takeDamage(17);
	don.takeDamage(61);
	ron.takeDamage(12);

	return (0);
}