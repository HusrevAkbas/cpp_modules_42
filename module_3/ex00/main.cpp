/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:09:59 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/06 22:40:53 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	rob("Rob");

	rob.attack("Robert");
	rob.takeDamage(9);
	rob.takeDamage(3);
	rob.attack("Robert");
	rob.beRepaired(4);

	std::cout << "------------------------------" << std::endl;

	ClapTrap	wendy("Wendy");

	wendy.attack("Junior");
	wendy.takeDamage(2);
	wendy.beRepaired(5);
	wendy.takeDamage(3);

	std::cout << "------------------------------" << std::endl;

	ClapTrap	noname("The Last Warior");

	for (size_t i = 0; i < 7; i++)
		noname.attack("ENEMY");
	for (size_t i = 0; i < 7; i++)
		noname.beRepaired(1);
	noname.attack("lion");

	return (0);
}
