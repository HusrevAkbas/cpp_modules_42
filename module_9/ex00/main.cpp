/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:25:20 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/09/22 13:37:21 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static void	printValueError(int err_code)
{
	switch (err_code)
	{
	case -1:
		std::cerr << RED << "Error: value is not a number\n" << RESET;
		break;
	case -2:
		std::cerr << RED << "Error: too large number\n" << RESET;
		break;
	case -3:
		std::cerr << RED << "Error: not a positive number\n" << RESET;
		break;
	default:
		break;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Argument needed:\n./btc inputFile\n" << RESET;
		return (1);
	}

	// reads database and sets map in constructor
	BitcoinExchange	btc;

	// read input file
	std::string	filename(argv[1]);
	std::fstream	inputFile(filename.c_str(), std::fstream::in);
	if (!inputFile)
	{
		std::cerr << RED << "Failed to open input file\n" << RESET;
		return (2);
	}

	std::string	line;
	std::string	date;
	std::string	value;
	time_t		date_time;
	double		value_d;
	size_t		index_delimiter;
	bool		title_pass = false;

	// get dates and values line by line
	while (std::getline(inputFile, line))
	{
		// skip empty lines
		if (line.empty())
			continue ;
		BitcoinExchange::trim(line);
		index_delimiter = line.find('|');
		if (index_delimiter == std::string::npos)
		{
			std::cerr << RED << "Error: bad input => " << RESET << line << "\n";
			continue ;
		}

		// get date and validate
		date = line.substr(0, index_delimiter);
		date_time = btc.validateDate(date);
		if (!date_time)
		{
			if (!title_pass)
			{
				title_pass = true;
				continue ;
			}
			else
				std::cerr << RED << "Error: invalid date => " << RESET << line << "\n";
			continue ;
		}

		// get value and validate
		value = line.substr(index_delimiter + 1);
		value_d = btc.validateValue(value);
		if (value_d > 1000)
			value_d = -2;
		if (value_d < 0)
		{
			printValueError(value_d);
			title_pass = true;
			continue ;
		}

		// find currency in database
		double	btc_value = btc.getValue(date_time / SECS_PER_DAY);
		if (btc_value == -1)
		{
			std::cerr << RED << "Error: date is too early " << RESET << date << "\n";
			title_pass = true;
			continue ;
		}

		// print result
		std::cout << date << " => " << value_d << " = " << value_d * btc_value << "\n";
		title_pass = true;
	}
	return (0);
}
