/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:46:39 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/22 19:55:01 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	Zombie		*horde;
	int			count;
	std::string	name;
	std::string	num;

	name = "mickey";
	count = 10;
	if (argc == 3)
	{
		num = argv[1];
		count = std::stoi(num);
		name = argv[2];
	}
	horde = zombieHorde(count, name);
	for (int i = 0; i < count; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
