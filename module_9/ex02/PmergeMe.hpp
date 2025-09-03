/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:37:04 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/03 15:51:58 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

#include <vector>
#include <deque>

#define	RED		"\e[1;31m"
#define RESET	"\e[0m"

size_t	get_next_Jacobsthal_difference(bool	reset);
void	init_vector(std::vector<std::string> &arguments, std::vector<int> *vec, std::deque<int> *deq);
void	init_arguments(int argc, char **argv, std::vector<std::string> *arguments);
void	ft_divide_and_swap_pairs(std::vector<int> *vec, size_t item_per_pair);
