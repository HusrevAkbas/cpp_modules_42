/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_pairs.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:44:08 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/09 12:48:46 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	ft_divide_and_swap_pairs(std::vector<int> *vec, size_t item_per_pair)
{
	std::vector<int>::iterator	it_first;
	std::vector<int>::iterator	it_last;
	std::vector<int>::iterator	it_last_of_second_pair;
	std::vector<int>::iterator	it_last_of_first_pair;
	std::vector<int>::iterator	it_swap;

	// print_vector(*vec, "pairs before swap", item_per_pair);

	for (size_t i = item_per_pair - 1; i + item_per_pair < vec->size(); i += item_per_pair * 2)
	{
		it_first = vec->begin() + i - item_per_pair + 1;
		it_last = vec->begin() + i + 1;
		it_last_of_first_pair = vec->begin() + i;
		it_last_of_second_pair = vec->begin() + i + item_per_pair;
		it_swap = it_last;
		counter++;
		if (*it_last_of_first_pair > *it_last_of_second_pair)
			std::swap_ranges(it_first, it_last, it_swap);
	}

	// print_vector(*vec, "pairs after swap", item_per_pair);
	// std::cout << "\n";
}

void	ft_divide_and_swap_pairs_deque(std::deque<int> *deq, size_t item_per_pair)
{
	std::deque<int>::iterator	it_first;
	std::deque<int>::iterator	it_last;
	std::deque<int>::iterator	it_last_of_second_pair;
	std::deque<int>::iterator	it_last_of_first_pair;
	std::deque<int>::iterator	it_swap;

	// print_deque(*deq, "pairs before swap", item_per_pair);

	for (size_t i = item_per_pair - 1; i + item_per_pair < deq->size(); i += item_per_pair * 2)
	{
		it_first = deq->begin() + i - item_per_pair + 1;
		it_last = deq->begin() + i + 1;
		it_last_of_first_pair = deq->begin() + i;
		it_last_of_second_pair = deq->begin() + i + item_per_pair;
		it_swap = it_last;
		if (*it_last_of_first_pair > *it_last_of_second_pair)
			std::swap_ranges(it_first, it_last, it_swap);
	}

	// print_deque(*deq, "", item_per_pair);
	// std::cout << "\n";
}
