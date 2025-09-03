/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacobsthal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:35:55 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/03 14:36:47 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

size_t	get_next_Jacobsthal_difference(bool	reset)
{
	static	size_t	first = 1;
	static	size_t	second = 3;
	size_t			tmp;
	size_t			diff;

	if (reset)
	{
		first = 1;
		second = 3;
		return (0);
	}

	// save difference
	diff = second - first;

	// update next pair
	tmp = 2 * first + second;
	first = second;
	second = tmp;

	// return difference
	return (diff);
}
