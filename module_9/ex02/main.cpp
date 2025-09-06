/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:55:48 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/06 16:10:35 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	insert_pending_to_main_chain(std::vector<int> *main_chain, std::vector<int> *pending, size_t item_per_pair)
{
	(void) main_chain;
	(void) item_per_pair;
	size_t	items_to_insert;
	std::vector<int>::iterator	last_of_next_insertion;
	std::vector<int>::iterator	first_of_next_insertion;
	std::vector<int>::iterator	insert_in_main_chain;

	if (pending->size() == 0)
		return ;

	while (pending->size() > 0)
	{
	items_to_insert = get_next_Jacobsthal_difference(false);

	while (items_to_insert > 0)
	{
		// find item to insert next in pending
		if (items_to_insert >= pending->size() / item_per_pair)
		{
			last_of_next_insertion = pending->end() - 1;
			first_of_next_insertion = pending->end() - item_per_pair;
			items_to_insert = pending->size() / item_per_pair;
		}
		else
		{
			last_of_next_insertion = pending->begin() + item_per_pair * items_to_insert - 1;
			first_of_next_insertion = pending->begin() + item_per_pair * (items_to_insert - 1);
		}

		// std::cout << "items to insert " << items_to_insert << " pair size " << pending->size() / item_per_pair << "\n";
		// std::cout << "to insert: " << items_to_insert << " | " << *first_of_next_insertion << " | "
		// << *last_of_next_insertion << " item per pair: " << item_per_pair << "\n";
		
		// find insert index by binary search in main_chain
		insert_in_main_chain = binary_search(main_chain, *last_of_next_insertion, item_per_pair);
		// std::cout << " insert before: " << *insert_in_main_chain << "\n";
		
		main_chain->insert(insert_in_main_chain, first_of_next_insertion, last_of_next_insertion + 1);

		// remove inserted elements from pending
		pending->erase(first_of_next_insertion, last_of_next_insertion + 1);
		// print_vector(*pending, "after erase", item_per_pair);
		items_to_insert--;
	}

		// repeat as many times until nothing left to insert in pending
	}

	get_next_Jacobsthal_difference(true);
}

void	merge_insertion_sort_or_the_Ford_Johnson_algorithm
		(std::vector<int> *vec, size_t item_per_pair)
{
	if (item_per_pair > vec->size() / 2)
		return ;

	ft_divide_and_swap_pairs(vec, item_per_pair);

	merge_insertion_sort_or_the_Ford_Johnson_algorithm(vec, item_per_pair * 2);

	// std::cout << "\ninsert for " << item_per_pair << "\n";
	std::vector<int>	main_chain;
	std::vector<int>	pending;
	std::vector<int>	non_participant;

	std::vector<int>::iterator	it_start;
	std::vector<int>::iterator	it_end;
	std::vector<int>::iterator	it_insert;

	// print_vector(*vec, "", item_per_pair);

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

	// print_vector(main_chain, "main 0 : ", item_per_pair);
	// print_vector(pending, "pending: ", item_per_pair);
	// print_vector(non_participant, "nonpart: ", 1000);

	// insert pending to main chain using binary search
	insert_pending_to_main_chain(&main_chain, &pending, item_per_pair);

	// insert non participants to main chain
	main_chain.insert(main_chain.end(), non_participant.begin(), non_participant.end());

	// print_vector(main_chain, "main 1 : ", item_per_pair);

	// set vector to main chain so upper levels knows the change
	*vec = main_chain;
}

int	main(int argc, char **argv)
{
	std::vector<std::string>	argumentList;
	std::vector<int>			vec;
	std::deque<int>				deq;

	init_arguments(argc, argv, &argumentList);
	init_vector(argumentList, &vec, &deq);

	// test_binary_search();
	print_vector(vec, "", 1000);

	// std::cout << std::count(vec.begin(), vec.end(), 999) << "\n";

	merge_insertion_sort_or_the_Ford_Johnson_algorithm(&vec, 1);

	print_vector(vec, "", 1000);
	// std::cout << std::count(vec.begin(), vec.end(), 999) << "\n";

	return (0);
}
