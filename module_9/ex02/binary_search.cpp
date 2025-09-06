/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:33:53 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/06 15:25:12 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>::iterator	binary_search(std::vector<int> *main_chain, int search, size_t item_per_pair)
{
	// std::vector<int>::iterator	left;
	// std::vector<int>::iterator	right;
	// std::vector<int>::iterator	middle;
	// size_t						pair_size;
	// size_t						pair_index;

	size_t	left;
	size_t	right;
	size_t	middle;

	// print_vector(*main_chain, "", item_per_pair);
	// std::cout << search << "\n";

	left = 1;
	right = main_chain->size() / item_per_pair;

	while (left <= right)
	{
		middle = left + (right - left) / 2;
		if ((*main_chain)[middle * item_per_pair - 1] > search)
			right = middle - 1;
		else if ((*main_chain)[middle * item_per_pair - 1] < search)
			left = middle + 1;
		else
			break ;
	}
	// std::cout << middle << " : " << *(main_chain->begin() + (middle - 1) * item_per_pair) << "\n";
	// std::cout << left << " : " << *(main_chain->begin() + (left - 1) * item_per_pair) << "\n";
	return (main_chain->begin() + (left - 1) * item_per_pair);
}

void	test_binary_search()
{
	std::vector<int>	vic;
	for (size_t i = 0; i < 16; i++)
	{
		vic.push_back(i * 2);
	}
	std::cout << *(binary_search(&vic, 11, 2)) << "\n";
	std::cout << *(binary_search(&vic, 25, 2)) << "\n";
	std::cout << *(binary_search(&vic, 1, 2)) << "\n";
	std::cout << *(binary_search(&vic, 15, 2)) << "\n";
	std::cout << *(binary_search(&vic, 19, 2)) << "\n";
}