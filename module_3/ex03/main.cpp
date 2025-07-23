/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:19:21 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 23:07:25 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	don("Don");
	ClapTrap	claw("Claw");
	ScavTrap	sed("Sed");
	FragTrap	fred("Fred");

	don.attack("Ron");
	don.whoAmI();
	sed.guardGate();
	fred.highFivesGuys();
	claw.beRepaired(10);

	return (0);
}