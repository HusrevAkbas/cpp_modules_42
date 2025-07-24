/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:21:50 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 17:10:59 by huakbas          ###   ########.fr       */
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

	return (0);
}
