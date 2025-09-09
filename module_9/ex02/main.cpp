/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:55:48 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/09 13:06:42 by huakbas          ###   ########.fr       */
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
	init_vector(argumentList, &vec);
	init_deque(argumentList, &deq);

	print_vector(vec, "", 1000);

	const double	vector_start = std::clock();
	merge_insertion_sort_or_the_Ford_Johnson_algorithm_vector(&vec, 1);
	const double	vector_end = std::clock();

	const double	deque_start = std::clock();
	merge_insertion_sort_or_the_Ford_Johnson_algorithm_deque(&deq, 1);
	const double	deque_end = std::clock();

	print_vector(vec, "", 1000);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "
	<< (vector_end - vector_start) * 1000 / CLOCKS_PER_SEC << " ms. Comparison count: " << counter << "\n";
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : "
	<< (deque_end - deque_start) * 1000 / CLOCKS_PER_SEC << " ms. Comparison count: " << counter << "\n";

	return (0);
}
