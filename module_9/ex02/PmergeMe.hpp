/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:37:04 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/11 15:35:23 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

#include <vector>
#include <deque>

# define RED	"\e[1;31m"
# define GREEN	"\e[1;32m"
# define YELLOW	"\e[1;33m"
# define BLUE	"\e[1;34m"
# define MAGENT	"\e[1;35m"
# define CYAN	"\e[1;36m"
# define WHITE	"\e[1;37m"
# define RESET	"\e[0m"

extern int	counter;

size_t	get_next_Jacobsthal_difference(bool	reset);
void	init_vector(std::vector<std::string> &arguments, std::vector<int> &vec);
void	init_deque(std::vector<std::string> &arguments, std::deque<int> &deq);
void	init_arguments(int argc, char **argv, std::vector<std::string> *arguments);
void	ft_divide_and_swap_pairs(std::vector<int> *vec, size_t item_per_pair);
void	switch_output_color();
void	print_vector(std::vector<int> &vec, std::string note, size_t item_per_pair);
std::vector<int>::iterator	binary_search(std::vector<int> *main_chain, int search, size_t item_per_pair, size_t upper_bound);
void	merge_insertion_sort_or_the_Ford_Johnson_algorithm_vector
		(std::vector<int> *vec, size_t item_per_pair);
void	merge_insertion_sort_or_the_Ford_Johnson_algorithm_deque
		(std::deque<int> *deq, size_t item_per_pair);
std::deque<int>::iterator	binary_search_deque(std::deque<int> *main_chain, int search, size_t item_per_pair, size_t upper_bound);
void	ft_divide_and_swap_pairs_deque(std::deque<int> *deq, size_t item_per_pair);
void	print_deque(std::deque<int> &vec, std::string note, size_t item_per_pair);