/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:55:48 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/06 16:43:14 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	std::vector<std::string>	argumentList;
	std::vector<int>			vec;
	std::deque<int>				deq;

	init_arguments(argc, argv, &argumentList);
	init_vector(argumentList, &vec, &deq);

	print_vector(vec, "", 1000);
	merge_insertion_sort_or_the_Ford_Johnson_algorithm_vector(&vec, 1);
	print_vector(vec, "", 1000);

	print_deque(deq, "", 1000);
	merge_insertion_sort_or_the_Ford_Johnson_algorithm_deque(&deq, 1);
	print_deque(deq, "", 1000);

	return (0);
}
