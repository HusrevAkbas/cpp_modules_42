/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:55:48 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/02 14:55:16 by huakbas          ###   ########.fr       */
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

void	merge_insertion_sort_or_the_Ford_Johnson_algorithm
		(std::vector<int> *vec, size_t item_per_pair)
{
	if (item_per_pair > vec->size() / 2)
		return ;

	std::cout << std::endl;
	for (std::vector<int>::iterator i = vec->begin(); i != vec->end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	size_t	last_of_prev_pair;
	size_t	last_of_next_pair;
	std::vector<int>::iterator	it_first;
	std::vector<int>::iterator	it_last;
	std::vector<int>::iterator	it_swap;

	for (size_t i = item_per_pair - 1; i + item_per_pair < vec->size(); i += item_per_pair * 2)
	{
		last_of_prev_pair = i;
		last_of_next_pair = i + item_per_pair;
		std::cout << last_of_prev_pair << " | " << last_of_next_pair << " - " << item_per_pair <<  "\n";
		it_first = vec->begin() + i - item_per_pair + 1;
		it_last = vec->begin() + i + 1;
		it_swap = it_last;
		std::cout << "first it: " << *it_first << " last it: " << *it_last << " swap begins: " << *it_swap <<  "\n";
		std::swap_ranges(it_first, it_last, it_swap);
	}
	
	for (std::vector<int>::iterator i = vec->begin(); i != vec->end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	merge_insertion_sort_or_the_Ford_Johnson_algorithm(vec, item_per_pair * 2);
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
