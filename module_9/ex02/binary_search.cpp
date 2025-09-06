/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:33:53 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/06 17:35:13 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>::iterator	binary_search(std::vector<int> *main_chain, int search, size_t item_per_pair)
{
	size_t	left;
	size_t	right;
	size_t	middle;

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
	return (main_chain->begin() + (left - 1) * item_per_pair);
}

std::deque<int>::iterator	binary_search_deque(std::deque<int> *main_chain, int search, size_t item_per_pair)
{
	size_t	left;
	size_t	right;
	size_t	middle;

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
