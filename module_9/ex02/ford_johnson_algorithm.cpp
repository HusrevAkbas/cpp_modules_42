/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_johnson_algorithm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:31:47 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/11 15:09:11 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void	insert_pending_to_main_chain_vector(std::vector<int> *main_chain, std::vector<int> *pending, size_t item_per_pair)
{
	size_t	items_to_insert;
	size_t	items_inserted;
	std::vector<int>::iterator	last_of_next_insertion;
	std::vector<int>::iterator	first_of_next_insertion;
	std::vector<int>::iterator	insert_in_main_chain;
	size_t	upper_bound = 1;

	if (pending->size() == 0)
		return ;

	while (pending->size() > 0)
	{
		items_to_insert = get_next_Jacobsthal_difference(false);

		if (items_to_insert >= pending->size() / item_per_pair)
			items_to_insert = pending->size() / item_per_pair;

		upper_bound += items_to_insert;
		items_inserted = items_to_insert;

		while (items_to_insert > 0)
		{
			// find next elements to insert in pending
			last_of_next_insertion = pending->begin() + item_per_pair * items_to_insert - 1;
			first_of_next_insertion = pending->begin() + item_per_pair * (items_to_insert - 1);

			// find insert index by binary search in main_chain
			insert_in_main_chain = binary_search(main_chain, *last_of_next_insertion, item_per_pair, upper_bound);

			// insert next sequence into main chain
			main_chain->insert(insert_in_main_chain, first_of_next_insertion, last_of_next_insertion + 1);

			// remove inserted elements from pending
			pending->erase(first_of_next_insertion, last_of_next_insertion + 1);
			
			// go to next item to insert (previous index)
			items_to_insert--;
		}
		upper_bound += items_inserted;
		// repeat as many times until nothing left to insert in pending
	}

	get_next_Jacobsthal_difference(true);
}
static void	insert_pending_to_main_chain_deque(std::deque<int> *main_chain, std::deque<int> *pending, size_t item_per_pair)
{
	size_t	items_to_insert;
	size_t	items_inserted;
	std::deque<int>::iterator	last_of_next_insertion;
	std::deque<int>::iterator	first_of_next_insertion;
	std::deque<int>::iterator	insert_in_main_chain;
	size_t	upper_bound = 1;

	if (pending->size() == 0)
		return ;

	while (pending->size() > 0)
	{
		items_to_insert = get_next_Jacobsthal_difference(false);

		if (items_to_insert > pending->size() / item_per_pair)
			items_to_insert = pending->size() / item_per_pair;

		upper_bound += items_to_insert;
		items_inserted = items_to_insert;

		while (items_to_insert > 0)
		{
			// find item to insert next in pending
			last_of_next_insertion = pending->begin() + item_per_pair * items_to_insert - 1;
			first_of_next_insertion = pending->begin() + item_per_pair * (items_to_insert - 1);

			// find insert index by binary search in main_chain
			insert_in_main_chain = binary_search_deque(main_chain, *last_of_next_insertion, item_per_pair, upper_bound);

			// insert next sequence into main chain
			main_chain->insert(insert_in_main_chain, first_of_next_insertion, last_of_next_insertion + 1);

			// remove inserted elements from pending
			pending->erase(first_of_next_insertion, last_of_next_insertion + 1);
			
			// go to next item to insert (previous index)
			items_to_insert--;
		}
		upper_bound += items_inserted;
		// repeat as many times until nothing left to insert in pending
	}

	get_next_Jacobsthal_difference(true);
}

void	merge_insertion_sort_or_the_Ford_Johnson_algorithm_deque
		(std::deque<int> *deq, size_t item_per_pair)
{
	if (item_per_pair > deq->size() / 2)
		return ;

	ft_divide_and_swap_pairs_deque(deq, item_per_pair);

	merge_insertion_sort_or_the_Ford_Johnson_algorithm_deque(deq, item_per_pair * 2);

	// binary search insertion starts here
	std::deque<int>	main_chain;
	std::deque<int>	pending;
	std::deque<int>	non_participant;

	std::deque<int>::iterator	it_start;
	std::deque<int>::iterator	it_end;

	// set main chain
	main_chain.insert(main_chain.begin(), deq->begin(), deq->begin() + item_per_pair);
	for (size_t i = item_per_pair; i + item_per_pair <= deq->size(); i += 2 * item_per_pair)
	{
		it_start = deq->begin() + i;
		it_end = deq->begin() + i + item_per_pair;
		main_chain.insert(main_chain.end(), it_start, it_end);
	}

	// set pending
	for (size_t i = 2 * item_per_pair; i + item_per_pair <= deq->size(); i += 2 * item_per_pair)
	{
		it_start = deq->begin() + i;
		it_end = deq->begin() + i + item_per_pair;
		pending.insert(pending.end(), it_start, it_end);
	}

	// set non_participant items
	non_participant.insert(non_participant.begin(), deq->end() - (deq->size() % item_per_pair), deq->end());

	// insert pending to main chain using binary search
	insert_pending_to_main_chain_deque(&main_chain, &pending, item_per_pair);

	// insert non participants to main chain
	main_chain.insert(main_chain.end(), non_participant.begin(), non_participant.end());

	// assign main chain to deque so upper levels knows the change
	*deq = main_chain;
}

void	merge_insertion_sort_or_the_Ford_Johnson_algorithm_vector
		(std::vector<int> *vec, size_t item_per_pair)
{
	if (item_per_pair > vec->size() / 2)
		return ;

	ft_divide_and_swap_pairs(vec, item_per_pair);

	merge_insertion_sort_or_the_Ford_Johnson_algorithm_vector(vec, item_per_pair * 2);

	// binary search insertion starts here
	std::vector<int>	main_chain;
	std::vector<int>	pending;
	std::vector<int>	non_participant;

	std::vector<int>::iterator	it_start;
	std::vector<int>::iterator	it_end;

	// set main chain
	main_chain.insert(main_chain.begin(), vec->begin(), vec->begin() + item_per_pair);
	for (size_t i = item_per_pair; i + item_per_pair <= vec->size(); i += 2 * item_per_pair)
	{
		it_start = vec->begin() + i;
		it_end = vec->begin() + i + item_per_pair;
		main_chain.insert(main_chain.end(), it_start, it_end);
	}

	// set pending
	for (size_t i = 2 * item_per_pair; i + item_per_pair <= vec->size(); i += 2 * item_per_pair)
	{
		it_start = vec->begin() + i;
		it_end = vec->begin() + i + item_per_pair;
		pending.insert(pending.end(), it_start, it_end);
	}

	// set non_participant items
	non_participant.insert(non_participant.begin(), vec->end() - (vec->size() % item_per_pair), vec->end());

	// insert pending to main chain using binary search
	insert_pending_to_main_chain_vector(&main_chain, &pending, item_per_pair);

	// insert non participants to main chain
	main_chain.insert(main_chain.end(), non_participant.begin(), non_participant.end());

	// assign main chain to vector so upper levels knows the change
	*vec = main_chain;
}
