/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:21:17 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/08 14:50:20 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main()
{
	AMateria	*ice = new Ice();
	AMateria	*cure = new Cure();
	AMateria	*ice_clone = ice->clone();
	AMateria	*cure_clone = cure->clone();
	ICharacter	*rogue = new Character( "rogue" );
	ICharacter	*magie = new Character( "magie" );

	rogue->equip(ice_clone);
	rogue->equip(cure_clone);
	rogue->equip(ice);
	rogue->equip(NULL);
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << rogue->getName() << " ";
		rogue->use(i, *magie);
	}
	rogue->unequip(2);
	rogue->unequip(1);
	magie->equip(ice);
	magie->equip(cure);
	magie->equip(cure_clone);
	magie->equip(ice_clone);
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << magie->getName() << " ";
		magie->use(i, *rogue);
	}
	delete rogue;
	delete magie;
	return (0);
}
