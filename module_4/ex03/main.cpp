/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:21:17 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/25 17:09:39 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main()
{
	Ice		*ice = new Ice();
	Cure	*cure = new Cure();
	Ice		*ice_clone = ice->clone();
	Cure	*cure_clone = cure->clone();
	ICharacter	*rogue = new Character();

	rogue->equip(ice_clone);
	rogue->equip(cure_clone);
	rogue->equip(ice);
	rogue->equip(cure);
	for (size_t i = 0; i < 4; i++)
		rogue->use(i, *rogue);
	rogue->unequip(2);
	for (size_t i = 0; i < 4; i++)
		rogue->use(i, *rogue);
	delete (rogue);
	delete (ice);
	return (0);
}
