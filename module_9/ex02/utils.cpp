/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:06:07 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/15 17:35:23 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	switch_output_color()
{
	static unsigned int	i = 0;
	switch (i % 4)
	{
	case 0:
		std::cout << CYAN;
		break;
	case 1:
		std::cout << MAGENT;
		break;
	case 2:
		std::cout << BLUE;
		break;
	case 3:
		std::cout << RED;
		break;
	default:
		break;
	}
	i++;
}

void	print_vector(std::vector<int> &vec, std::string note, size_t item_per_pair)
{
	if (!note.empty())
		std::cout << note << "\n";
	for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
	{
		if ( i - vec.begin() != 0 && (i - vec.begin()) % (2 * item_per_pair) == 0)
			std::cout << RESET << "- ";
		if ((i - vec.begin()) % item_per_pair == 0)
			switch_output_color();
		std::cout << *i << " ";
	}
	std::cout << RESET << std::endl;
}

void	print_deque(std::deque<int> &vec, std::string note, size_t item_per_pair)
{
	if (!note.empty())
		std::cout << note << "\n";
	for (std::deque<int>::iterator i = vec.begin(); i != vec.end(); i++)
	{
		if ( i - vec.begin() != 0 && (i - vec.begin()) % (2 * item_per_pair) == 0)
			std::cout << RESET << "- ";
		if ((i - vec.begin()) % item_per_pair == 0)
			switch_output_color();
		std::cout << *i << " ";
	}
	std::cout << RESET << std::endl;
}
