/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:25:20 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/09/22 14:57:09 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Argument needed:\n./btc inputFile\n" << RESET;
		return (1);
	}

	// reads database and sets map in constructor
	BitcoinExchange	btc;

	if (!btc.databaseReady())
		return (1);

	btc.calculateExchange(argv[1]);

	return (0);
}
