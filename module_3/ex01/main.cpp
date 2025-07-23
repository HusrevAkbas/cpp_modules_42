/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:14:54 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/23 18:19:02 by huakbas          ###   ########.fr       */
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
	wendy.takeDamage(19);
	return (0);
}

