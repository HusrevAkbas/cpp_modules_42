/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:23:20 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 21:53:45 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	ron( "Ron" );
	ScavTrap	don( "Don" );
	FragTrap	son( "Son" );
	ScavTrap	rep;

	rep = don;
	rep.guardGate();
	son.highFivesGuys();
	son.attack( "Danny");
	don.attack("Yen");
	ron.attack("Saun");

	son.beRepaired(8);
	don.beRepaired(18);
	ron.beRepaired(28);
	rep.beRepaired(1);

	son.takeDamage(17);
	don.takeDamage(61);
	ron.takeDamage(12);
	rep.takeDamage(3);

	return (0);
}