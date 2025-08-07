/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:19:21 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/07 12:18:48 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	don("Don");

	don.attack("Ron");
	don.whoAmI();
	don.takeDamage(111);
	don.beRepaired(10);
	don.guardGate();
	don.highFivesGuys();

	return (0);
}