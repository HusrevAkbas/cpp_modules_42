/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:21:50 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/11 17:02:40 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main ()
{
	size_t	count = 11;
	Animal	*animals[count];

	// Create half of count times Cat s
	for (size_t i = 0; i < count / 2; i++)
		animals[i] = new Cat();

	// Create rest of count times Dog s
	for (size_t i = count / 2; i < count; i++)
		animals[i] = new Dog();

	// Animals makes sound
	for (size_t i = 0; i < count; i++)
		animals[i]->make_sound();

	// Delete all animals one by one
	for (size_t i = 0; i < count; i++)
		delete animals[i];

	/*	DEEP COPY TEST	*/
	std::cout << "--------------------------------------" << std::endl;

	Cat caddy = Cat();
	caddy.getBrain()->setIdea(0, "It would be nice to go home.");
	caddy.getBrain()->setIdea(1, "Take a seat, lean back and enjoy.");
	Cat canny = Cat(caddy);
	std::cout << canny.getBrain()->getIdea(0) << std::endl;
	std::cout << canny.getBrain()->getIdea(1) << std::endl;
	std::cout << caddy.getBrain()->getIdea(0) << std::endl;
	std::cout << caddy.getBrain()->getIdea(1) << std::endl;

	std::cout << "--------------------------------------" << std::endl;

	caddy.getBrain()->setIdea(0, "Hard work .. .. .. Hard work");
	caddy.getBrain()->setIdea(1, "Take a deep breath than the leap of faith");
	std::cout << canny.getBrain()->getIdea(0) << std::endl;
	std::cout << canny.getBrain()->getIdea(1) << std::endl;
	std::cout << caddy.getBrain()->getIdea(0) << std::endl;
	std::cout << caddy.getBrain()->getIdea(1) << std::endl;

	Dog daddy = Dog();
	daddy.getBrain()->setIdea(0, "Daddy It would be nice to go home.");
	daddy.getBrain()->setIdea(1, "Daddy Take a seat, lean back and enjoy.");
	Dog danny = Dog();
	danny = daddy;
	std::cout << danny.getBrain()->getIdea(0) << std::endl;
	std::cout << danny.getBrain()->getIdea(1) << std::endl;
	std::cout << daddy.getBrain()->getIdea(0) << std::endl;
	std::cout << daddy.getBrain()->getIdea(1) << std::endl;

	std::cout << "--------------------------------------" << std::endl;

	daddy.getBrain()->setIdea(0, "Daddy Hard work .. .. .. Hard work");
	daddy.getBrain()->setIdea(1, "Daddy Take a deep breath than the leap of faith");
	std::cout << danny.getBrain()->getIdea(0) << std::endl;
	std::cout << danny.getBrain()->getIdea(1) << std::endl;
	std::cout << daddy.getBrain()->getIdea(0) << std::endl;
	std::cout << daddy.getBrain()->getIdea(1) << std::endl;

	return (0);
}
