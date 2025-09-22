/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:17:55 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/22 17:18:21 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	std::vector<std::string>	argumentList;
	std::vector<int>			vec;
	std::deque<int>				deq;
	
	init_arguments(argc, argv, &argumentList);

	if (argumentList.size() == 0)
	{
		std::cerr << RED << "Error: need integer arguments. Example: \n" << RESET;
		std::cerr << RED << "./PmergeMe 3 2 1\n" << RESET;
		exit (1);
	}

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
