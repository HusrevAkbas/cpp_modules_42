/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:09:59 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/23 16:57:05 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	rob("Rob");
	ClapTrap	wendy("Wendy");
	ClapTrap	noname("last warior");

	rob.attack("Robert");
	wendy.attack("Junior");
	rob.takeDamage(9);
	noname.attack("Evaluated");
	noname = rob;
	rob.takeDamage(3);
	wendy.takeDamage(2);
	rob.beRepaired(4);
	noname.takeDamage(5);
	wendy.beRepaired(5);
	return (0);
}
