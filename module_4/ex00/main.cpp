/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:21:50 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/09 15:49:42 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main ()
{
	Animal	*meta = new Animal ("Bird");

	std::cout << "meta: Animal class" << std::endl;
	std::cout << meta->get_type() << " says: ";
	meta->make_sound();
	delete meta;

	std::cout << "----------------------------" << std::endl;

	Dog		*dog = new Dog ();

	std::cout << "dog: Dog class" << std::endl;
	std::cout << dog->get_type() << " says: ";
	dog->make_sound();
	delete dog;

	std::cout << "----------------------------" << std::endl;

	Cat		*cat = new Cat ();

	std::cout << "cat: Cat class" << std::endl;
	std::cout << cat->get_type() << " says: ";
	cat->make_sound();
	delete cat;

	std::cout << "----------------------------" << std::endl;

	Animal	*a = new Cat ();

	std::cout << "a: Cat class" << std::endl;
	std::cout << a->get_type() << " says: ";
	a->make_sound();
	delete a;

	a = new Dog ();

	std::cout << "a: Dog class" << std::endl;
	std::cout << a->get_type() << " says: ";
	a->make_sound();
	delete a;

	std::cout << "----------------------------" << std::endl;

	WrongAnimal	*wrong_animal = new WrongAnimal();
	WrongAnimal	*wrong_cat = new WrongCat();
	wrong_animal->make_sound();
	wrong_cat->make_sound();
	delete wrong_animal;
	delete wrong_cat;

	return (0);
}
