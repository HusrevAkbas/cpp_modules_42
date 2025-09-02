/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:55:48 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/02 16:18:32 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

#include <vector>
#include <deque>

#define	RED		"\e[1;31m"
#define RESET	"\e[0m"

// inits containers with arguments given in quotes: "3 2 1"
void	init_containers(std::vector<std::string> &arguments, std::vector<int> *vec, std::deque<int> *deq)
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
		vec->push_back(num);
		deq->push_back(num);
	}
}

void	init_arguments(int argc, char **argv, std::vector<std::string> *arguments)
{
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
			arguments->push_back(argv[i]);
			i++;
		}
	}
	else
	{
		std::stringstream	ss(argv[1]);
		std::string			part;
		while (std::getline(ss, part, ' '))
		{
			arguments->push_back(part);
		}
	}
}

//	8 => pair of 4, 6 => pair of 2
size_t	find_power_of_two_divider(size_t size)
{
	size_t	divider = 2;
	while (size / divider > 2)
	{
		divider *= 2;
	}
	return (divider);
}

void	swap_pairs(std::vector<int> *vec, size_t item_per_pair)
{
	std::vector<int>::iterator	it_first;
	std::vector<int>::iterator	it_last;
	std::vector<int>::iterator	it_last_of_second_pair;
	std::vector<int>::iterator	it_last_of_first_pair;
	std::vector<int>::iterator	it_swap;

	for (size_t i = item_per_pair - 1; i + item_per_pair < vec->size(); i += item_per_pair * 2)
	{
		it_first = vec->begin() + i - item_per_pair + 1;
		it_last = vec->begin() + i + 1;
		it_last_of_first_pair = vec->begin() + i;
		it_last_of_second_pair = vec->begin() + i + item_per_pair;
		it_swap = it_last;
		std::cout << "last of first: " << *it_last_of_first_pair << " last of sec: " << *it_last_of_second_pair << "\n";
		std::cout << "first it: " << *it_first << " last it: " << *it_last << " swap begins: " << *it_swap <<  "\n";
		if (*it_last_of_first_pair > *it_last_of_second_pair)
			std::swap_ranges(it_first, it_last, it_swap);
	}
}

void	insert_pend_to_main_chain(std::vector<int> *main_chain, std::vector<int> *pending, size_t item_per_pair)
{
	(void) main_chain;
	(void) item_per_pair;
	if (pending->size() == 0)
		return ;
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

	swap_pairs(vec, item_per_pair);

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

	std::cout << "main 0: ";
	for (std::vector<int>::iterator i = main_chain.begin(); i != main_chain.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	std::cout << "pendng: ";
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
	insert_pend_to_main_chain(&main_chain, &pending, item_per_pair);

	// insert non participants to main chain
	main_chain.insert(main_chain.end(), non_participant.begin(), non_participant.end());


	std::cout << "main 1: ";
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
	init_containers(argumentList, &vec, &deq);

	merge_insertion_sort_or_the_Ford_Johnson_algorithm(&vec, 1);

	
	return (0);
}
