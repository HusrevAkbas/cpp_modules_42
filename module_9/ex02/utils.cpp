/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:06:07 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/03 18:13:48 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	switch_output_color()
{
	static unsigned int	i = 0;
	switch (i % 4)
	{
	case 0:
		std::cout << RED;
		break;
	case 1:
		std::cout << YELLOW;
		break;
	case 2:
		std::cout << BLUE;
		break;
	case 3:
		std::cout << MAGENT;
		break;
	// case 4:
	// 	std::cout << MAGENT;
	// 	break;
	// case 5:
	// 	std::cout << MAGET;
	// 	break;
	// case 6:
	// 	std::cout << CYAN;
	// 	break;
	default:
		break;
	}
	i++;
}
