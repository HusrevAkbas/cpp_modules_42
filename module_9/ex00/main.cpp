/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:25:20 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/31 00:58:52 by husrevakbas      ###   ########.fr       */
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

	BitcoinExchange	btc;
	std::string	filename(argv[1]);
	std::fstream	inputFile(filename.c_str(), std::fstream::in);
	if (!inputFile)
	{
		std::cerr << RED << "Failed to open input file\n" << RESET;
		return (2);
	}

	std::string	line;
	std::getline(inputFile, line);	// skip titles
	if (inputFile.eof())
	{
		std::cerr << RED << "Input file is empty!\n" << RESET;
		return (3);
	}

	std::string	date;
	std::string	value;
	time_t		date_time;
	double		value_d;
	size_t		index_delimiter;

	std::getline(inputFile, line);
	while (!inputFile.eof())
	{
		index_delimiter = line.find('|');
		if (index_delimiter == std::string::npos)
		{
			std::cerr << RED << "Error: bad input => " << RESET << line << "\n";
			std::getline(inputFile, line);
			continue ;
		}

		// get date and validate
		date = line.substr(0, index_delimiter);
		date_time = btc.validateDate(date);
		if (!date_time)
		{
			std::cerr << RED << "Error: invalid date => " << RESET << line << "\n";
			std::getline(inputFile, line);
			continue ;
		}

		// get value and validate
		value = line.substr(index_delimiter + 1);
		value_d = btc.validateValue(value);
		if (value_d < 0)
		{
			printValueError(value_d);
			std::getline(inputFile, line);
			continue ;
		}
		double	btc_value = btc.getValue(date_time / SECS_PER_DAY);
		if (btc_value == -1)
		{
			std::cerr << RED << "Error: date is too early " << RESET << date << "\n";
			std::getline(inputFile, line);
			continue ;
		}
		std::cout << date << " => " << value_d << " = " << value_d * btc_value << "\n";
		std::getline(inputFile, line);
	}
	return (0);
}
