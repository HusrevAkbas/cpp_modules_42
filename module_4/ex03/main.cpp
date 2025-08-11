/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:21:17 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/11 14:05:25 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main()
{
	/*	Manual Test	*/
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
		rogue->use(i, *magie);
	rogue->unequip(2);
	rogue->unequip(1);

	magie->equip(ice);
	magie->equip(cure);
	magie->equip(cure_clone);
	magie->equip(ice_clone);
	for (size_t i = 0; i < 4; i++)
		magie->use(i, *rogue);

	delete rogue;
	delete magie;

	std::cout << "--------------------------------" << std::endl;

	/*	Original Test*/
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	me->getName();
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << "--------------------------------" << std::endl;

	/*	Deep Copy Test	*/
	ice = new Ice();
	cure = new Cure();
	Character	a = Character("Alpha");
	a.equip(ice);
	Character	b = Character("Beethoven");
	b.equip(cure);
	a.use(0, b);
	a.use(1, b);
	b.use(0, a);
	b.use(1, a);
	b = a;
	std::cout << "a uses" << std::endl;
	a.use(0, b);
	a.use(1, b);
	std::cout << "b uses" << std::endl;
	b.use(0, a);
	b.use(1, a);

	return (0);
}
