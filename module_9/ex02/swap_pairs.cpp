/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_pairs.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:44:08 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/03 18:17:14 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	ft_divide_and_swap_pairs(std::vector<int> *vec, size_t item_per_pair)
{
	std::vector<int>::iterator	it_first;
	std::vector<int>::iterator	it_last;
	std::vector<int>::iterator	it_last_of_second_pair;
	std::vector<int>::iterator	it_last_of_first_pair;
	std::vector<int>::iterator	it_swap;

	// std::cout << item_per_pair << " : ";
	// for (std::vector<int>::iterator i = vec->begin(); i != vec->end(); i++)
	// {
	// 	if ((i - vec->begin()) % item_per_pair == 0)
	// 		switch_output_color();
	// 	std::cout << *i << " ";
	// }
	// std::cout << RESET << "\n";

	for (size_t i = item_per_pair - 1; i + item_per_pair < vec->size(); i += item_per_pair * 2)
	{
		it_first = vec->begin() + i - item_per_pair + 1;
		it_last = vec->begin() + i + 1;
		it_last_of_first_pair = vec->begin() + i;
		it_last_of_second_pair = vec->begin() + i + item_per_pair;
		it_swap = it_last;
		// std::cout << "last of first: " << *it_last_of_first_pair << " last of sec: " << *it_last_of_second_pair << "\n";
		// std::cout << "first it: " << *it_first << " last it: " << *it_last << " swap begins: " << *it_swap <<  "\n";
		if (*it_last_of_first_pair > *it_last_of_second_pair)
			std::swap_ranges(it_first, it_last, it_swap);
	}

	// std::cout << item_per_pair << " : ";
	// for (std::vector<int>::iterator i = vec->begin(); i != vec->end(); i++)
	// {
	// 	std::cout << *i << " ";
	// }
	// std::cout << "\n";
}
