/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:49:02 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 13:44:37 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	std::string	level;
	Harl	harl;
	std::string	array[4] = { "debug", "info", "warning", "error"};

	(void) argc;
	level = "";
	if (argv[1])
		level = argv[1];
	harl.complain(level);
/*
	// print all
	for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		harl.complain(array[i]);
	
	// print false arguments
	for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		harl.complain(&array[i][1]);
		
	// print all reverse order
	for (size_t i = sizeof(array) / sizeof(array[0]); i > 0 ; )
		harl.complain(array[--i]);
*/
	return (0);
}
