/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:14:54 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/06 22:58:45 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main ()
{
	ClapTrap	rob("rob");
	ScavTrap	wendy("wendy");

	rob.attack("junior");
	wendy.attack("invisible target");
	wendy.guardGate();
	rob.takeDamage(1);
	wendy.takeDamage(222);
	wendy.attack("Thanos");
	return (0);
}

