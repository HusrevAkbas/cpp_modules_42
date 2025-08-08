/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:21:50 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/08 13:39:55 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main ()
{
	Animal	*meta = new Animal ("Bird");

	std::cout << meta->get_type() << " says: ";
	meta->make_sound();

	Dog		*dog = new Dog ("Horse");

	std::cout << dog->get_type() << " says: ";
	dog->make_sound();

	Cat		*cat = new Cat ("Zebra");

	std::cout << cat->get_type() << " says: ";
	cat->make_sound();

	Animal	*a = new Cat ("Duck");

	std::cout << a->get_type() << " says: ";
	a->make_sound();

	Animal	*b = new Dog ("Wolf");

	std::cout << b->get_type() << " says: ";
	b->make_sound();

	WrongAnimal	*wrong_animal = new WrongAnimal();
	WrongAnimal	*wrong_cat = new WrongCat();
	wrong_animal->make_sound();
	wrong_cat->make_sound();

	delete meta;
	delete dog;
	delete cat;
	delete a;
	delete b;
	return (0);
}
