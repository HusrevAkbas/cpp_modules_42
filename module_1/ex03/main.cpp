/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:02:35 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 12:26:03 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		Weapon spear = Weapon("dragon lance");
		HumanA bob("Bob", club);
		HumanA witcher("Geralt", spear);

		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		witcher.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		Weapon spear = Weapon("dragon lance");
		HumanB jim("Jim");

		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		jim.setWeapon(spear);
		jim.attack();
	}
	return 0;
}
