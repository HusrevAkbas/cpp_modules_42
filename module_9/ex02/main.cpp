/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:55:48 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/15 17:34:09 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	counter = 0;

int	main(int argc, char **argv)
{
	std::vector<std::string>	argumentList;
	std::vector<int>			vec;
	std::deque<int>				deq;
	
	init_arguments(argc, argv, &argumentList);

	std::cout << GREEN;
	for (std::vector<std::string>::iterator it = argumentList.begin(); it != argumentList.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << RESET << "\n";
	
	
	
	const double	vector_start = std::clock();
	vec.resize(argumentList.size());
	init_vector(argumentList, vec);
	merge_insertion_sort_or_the_Ford_Johnson_algorithm_vector(&vec, 1);
	const double	vector_end = std::clock();
	
	const double	deque_start = std::clock();
	deq.resize(argumentList.size());
	init_deque(argumentList, deq);
	merge_insertion_sort_or_the_Ford_Johnson_algorithm_deque(&deq, 1);
	const double	deque_end = std::clock();

	print_vector(vec, "", vec.size());
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "
	<< (vector_end - vector_start) * 1000 / CLOCKS_PER_SEC << " ms. Comparison count: " << counter << "\n";
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : "
	<< (deque_end - deque_start) * 1000 / CLOCKS_PER_SEC << " ms. Comparison count: " << counter << "\n";

	return (0);
}
