/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:37:04 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/03 18:13:15 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

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

size_t	get_next_Jacobsthal_difference(bool	reset);
void	init_vector(std::vector<std::string> &arguments, std::vector<int> *vec, std::deque<int> *deq);
void	init_arguments(int argc, char **argv, std::vector<std::string> *arguments);
void	ft_divide_and_swap_pairs(std::vector<int> *vec, size_t item_per_pair);
void	switch_output_color();
