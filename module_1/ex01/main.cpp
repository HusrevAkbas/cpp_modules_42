/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:46:39 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/04 12:41:33 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie		*horde;
	int			count;
	std::string	name;

	name = "mickey";
	count = 10;

	horde = zombieHorde(count, name);

	for (int i = 0; i < count; i++)
		horde[i].announce();

	delete[] horde;

	return (0);
}
