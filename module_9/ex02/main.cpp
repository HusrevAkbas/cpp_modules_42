/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:55:48 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/03 18:28:48 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>::iterator	search_binary(std::vector<int> *main_chain, std::vector<int>::iterator last_of_next, size_t item_per_pair)
{
	std::vector<int>::iterator	start;
	std::vector<int>::iterator	end;
	std::vector<int>::iterator	middle;

	start = main_chain->begin();
	end = main_chain->end();
	size_t	diff = (end - start) / item_per_pair / 2;
	middle = start + diff * item_per_pair - 1;
	std::cout << "diff: " << diff << " middle: " << *middle << std::endl;
	(void) last_of_next;
	(void) item_per_pair;
	return (start);
}

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
	items_to_insert = get_next_Jacobsthal_difference(false);

	if (items_to_insert >= pending->size() / item_per_pair)
	{
		last_of_next_insertion = pending->end() - 1;
		first_of_next_insertion = pending->end() - item_per_pair;
	}
	else
	{
		last_of_next_insertion = pending->begin() + item_per_pair * items_to_insert - 1;
		first_of_next_insertion = pending->begin() + item_per_pair * (items_to_insert - 1);
	}

	std::cout << items_to_insert << " | " << *last_of_next_insertion << " | " << *first_of_next_insertion << "\n";
	
	// find item to insert next in pending
	// binary search item in main_chain
	// insert item to main chain, go next
	// remove inserted elements from pending
	// repeat as many times until nothing left to insert in pending

	get_next_Jacobsthal_difference(true);
}

void	merge_insertion_sort_or_the_Ford_Johnson_algorithm
		(std::vector<int> *vec, size_t item_per_pair)
{
	if (item_per_pair > vec->size() / 2)
		return ;

	// // uncomment to see the sequence
	// std::cout << std::endl;
	// std::cout << "pair for " << item_per_pair << "\n";
	// for (std::vector<int>::iterator i = vec->begin(); i != vec->end(); i++)
	// {
	// 	std::cout << *i << " ";
	// }
	// std::cout << std::endl;

	ft_divide_and_swap_pairs(vec, item_per_pair);

	// //	uncomment to see the change
	// for (std::vector<int>::iterator i = vec->begin(); i != vec->end(); i++)
	// {
	// 	std::cout << *i << " ";
	// }
	// std::cout << std::endl;

	merge_insertion_sort_or_the_Ford_Johnson_algorithm(vec, item_per_pair * 2);

	std::cout << "\ninsert for " << item_per_pair << "\n";
	std::vector<int>	main_chain;
	std::vector<int>	pending;
	std::vector<int>	non_participant;

	std::vector<int>::iterator	it_start;
	std::vector<int>::iterator	it_end;
	std::vector<int>::iterator	it_insert;

	for (std::vector<int>::iterator i = vec->begin(); i != vec->end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

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
	non_participant.insert(non_participant.end(), it_end, vec->end());

	std::cout << "main 0 : ";
	for (std::vector<int>::iterator i = main_chain.begin(); i != main_chain.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	std::cout << "pending: ";
	for (std::vector<int>::iterator i = pending.begin(); i != pending.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	std::cout << "nonpart: ";
	for (std::vector<int>::iterator i = non_participant.begin(); i != non_participant.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	// insert pending to main chain using binary search
	insert_pending_to_main_chain(&main_chain, &pending, item_per_pair);

	// insert non participants to main chain
	main_chain.insert(main_chain.end(), non_participant.begin(), non_participant.end());


	std::cout << "main 1 : ";
	for (std::vector<int>::iterator i = main_chain.begin(); i != main_chain.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	// set vector to main chain so upper levels knows the change
	// *vec = main_chain;
}

int	main(int argc, char **argv)
{
	std::vector<std::string>	argumentList;
	std::vector<int>			vec;
	std::deque<int>				deq;

	init_arguments(argc, argv, &argumentList);
	init_vector(argumentList, &vec, &deq);

	// for (std::vector<int>::iterator i = vec.begin(); i < vec.end(); i++)
	// {
	// 	std::cout << *i << " ";
	// }
	// std::cout << std::endl;

	// vec.insert(vec.begin() + 2, -99);

	// for (std::vector<int>::iterator i = vec.begin(); i < vec.end(); i++)
	// {
	// 	std::cout << *i << " ";
	// }
	// std::cout << std::endl;

	merge_insertion_sort_or_the_Ford_Johnson_algorithm(&vec, 1);

	
	return (0);
}
