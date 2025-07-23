/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:46:39 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 12:39:53 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	set_args(char **argv, std::string *name, int *count)
{
	std::string num;
	bool		is_num;

	is_num = true;
	num = argv[1];
	for (size_t i = 0; i < num.length(); i++)
	{
		if (!isdigit(num[i]))
		{
			is_num = false;
			break ;
		}
	}
	if (is_num)
	{
		*count = std::stoi(num);
		*name = argv[2];
	}
}

int	main(int argc, char **argv)
{
	Zombie		*horde;
	int			count;
	std::string	name;

	name = "mickey";
	count = 10;
	if (argc == 3)
		set_args(argv, &name, &count);

	horde = zombieHorde(count, name);

	for (int i = 0; i < count; i++)
		horde[i].announce();

	delete[] horde;

	return (0);
}
