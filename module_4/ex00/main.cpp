/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:21:50 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/07 13:00:14 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main ()
{
	Animal	*meta = new Animal ();
	Dog		*dog = new Dog ();
	Cat		*cat = new Cat ();
	Animal	*a = new Cat ();
	Animal	*b = new Dog ();

	std::cout << meta->get_type() << " says: ";
	meta->make_sound();
	std::cout << dog->get_type() << " says: ";
	dog->make_sound();
	std::cout << cat->get_type() << " says: ";
	cat->make_sound();
	std::cout << a->get_type() << " says: ";
	a->make_sound();
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
