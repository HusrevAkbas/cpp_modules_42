/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:55:48 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/22 17:23:00 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	counter = 0;

// inits containers with arguments for vector given in quotes: "3 2 1"
void	init_vector(std::vector<std::string> &arguments, std::vector<int> &vec)
{
	int					num;
	std::stringstream	sspart;

	for (std::vector<std::string>::iterator it = arguments.begin(); it != arguments.end(); it++)
	{
		sspart.clear();
		sspart.str(*it);
		sspart >> num;
		if (sspart.fail())
		{
			std::cerr << RED << "Error: invalid input: " << *it << "\n" << RESET;
			exit(2);
		}
		if (num <= 0)
		{
			std::cerr << RED << "Error: number is not positive: " << *it << "\n" << RESET;
			exit(2);
		}
		vec[it - arguments.begin()] = num;
	}
}

// inits containers with arguments for deque given in quotes: "3 2 1"
void	init_deque(std::vector<std::string> &arguments, std::deque<int> &deq)
{
	int					num;
	std::stringstream	sspart;

	for (std::vector<std::string>::iterator it = arguments.begin(); it != arguments.end(); it++)
	{
		sspart.clear();
		sspart.str(*it);
		sspart >> num;
		if (sspart.fail())
		{
			std::cerr << RED << "Error: invalid input: " << *it << "\n" << RESET;
			exit(2);
		}
		deq[it - arguments.begin()] = num;
	}
}

void	init_arguments(int argc, char **argv, std::vector<std::string> *arguments)
{
	std::string			part;
	if (argc < 2)
	{
		std::cerr << RED << "Error: need integer arguments. Example: \n" << RESET;
		std::cerr << RED << "./PmergeMe 3 2 1\n" << RESET;
		exit (1);
	}
	else if (argc > 2)
	{
		int	i = 1;
		while (argv[i])
		{
			part = argv[i];
			if (part.find_first_not_of("1234567890 ") != std::string::npos)
			{
				std::cerr << RED << "Error: invalid char in sequence " << part << RESET << "\n";
				exit (3);
			}
			arguments->push_back(part);
			i++;
		}
	}
	else
	{
		std::stringstream	ss(argv[1]);
		while (std::getline(ss, part, ' '))
		{
			if (part.find_first_not_of("1234567890 ") != std::string::npos)
			{
				std::cerr << RED << "Error: invalid char in sequence " << part << RESET << "\n";
				exit (3);
			}
			if (!part.empty())
				arguments->push_back(part);
		}
	}
}

size_t	get_next_Jacobsthal_difference(bool	reset)
{
	static	size_t	first = 1;
	static	size_t	second = 3;
	size_t			tmp;
	size_t			diff;

	if (reset)
	{
		first = 1;
		second = 3;
		return (0);
	}

	// save difference
	diff = second - first;

	// update next pair
	tmp = 2 * first + second;
	first = second;
	second = tmp;

	// return difference
	return (diff);
}

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

void	ft_divide_and_swap_pairs(std::vector<int> *vec, size_t item_per_pair)
{
	std::vector<int>::iterator	it_first;
	std::vector<int>::iterator	it_last;
	std::vector<int>::iterator	it_last_of_second_pair;
	std::vector<int>::iterator	it_last_of_first_pair;

	// print_vector(*vec, "pairs before swap", item_per_pair);

	for (size_t i = item_per_pair - 1; i + item_per_pair < vec->size(); i += item_per_pair * 2)
	{
		it_first = vec->begin() + i - item_per_pair + 1;
		it_last = vec->begin() + i + 1;
		it_last_of_first_pair = vec->begin() + i;
		it_last_of_second_pair = vec->begin() + i + item_per_pair;
		counter++;
		if (*it_last_of_first_pair > *it_last_of_second_pair)
			std::swap_ranges(it_first, it_last, it_last);
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

	// print_deque(*deq, "pairs before swap", item_per_pair);

	for (size_t i = item_per_pair - 1; i + item_per_pair < deq->size(); i += item_per_pair * 2)
	{
		it_first = deq->begin() + i - item_per_pair + 1;
		it_last = deq->begin() + i + 1;
		it_last_of_first_pair = deq->begin() + i;
		it_last_of_second_pair = deq->begin() + i + item_per_pair;
		if (*it_last_of_first_pair > *it_last_of_second_pair)
			std::swap_ranges(it_first, it_last, it_last);
	}

	// print_deque(*deq, "", item_per_pair);
	// std::cout << " SIZE " << deq->size() << "\n";
}

std::vector<int>::iterator	binary_search(std::vector<int> *main_chain, int search, size_t item_per_pair, size_t right)
{
	size_t	left;
	size_t	middle;

	left = 1;

	while (left <= right)
	{
		counter++;
		middle = left + (right - left) / 2;
		if ((*main_chain)[middle * item_per_pair - 1] < search)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return (main_chain->begin() + (left - 1) * item_per_pair);
}

std::deque<int>::iterator	binary_search_deque(std::deque<int> *main_chain, int search, size_t item_per_pair, size_t right)
{
	size_t	left;
	size_t	middle;

	left = 1;

	while (left <= right)
	{
		middle = left + (right - left) / 2;
		if ((*main_chain)[middle * item_per_pair - 1] < search)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return (main_chain->begin() + (left - 1) * item_per_pair);
}

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

