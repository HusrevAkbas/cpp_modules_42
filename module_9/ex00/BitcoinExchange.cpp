/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:36 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:18:58 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _db_filename("data.csv")
{
	getData();
}

BitcoinExchange::BitcoinExchange(std::string db_file = "data.csv")
: _db_filename(db_file)
{
	getData();
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &a)
{
	if (this == &a)
		return ;

	*this = a;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &a)
{
	if (this == &a)
		return (*this);

	this->_data = a._data;
	this->_db_filename = a._db_filename;
	return (*this);
}

void	BitcoinExchange::getData()
{
	std::ifstream	input_file(this->_db_filename.c_str());
	std::string		line;
	std::string		date;
	std::string		value;
	size_t			index_delimiter;
	if (!input_file)
		std::cout << RED << "Database couldn't found!\n" << RESET;

	std::getline(input_file, line);	// skip titles
	std::getline(input_file, line);
	while (!input_file.eof())
	{
		// std::cout << line << "\n";
		BitcoinExchange::trim(line);
		index_delimiter = line.find(",");
		date = line.substr(0, index_delimiter);
		validateDate(date);
		value = line.substr(index_delimiter + 1);
		// std::cout << index_delimiter << " " << date << " " << value << "\n";

		std::getline(input_file, line);
	}
	
	
}

void	BitcoinExchange::trim(std::string &str)
{
	std::remove_if(str.begin(), str.end(), isspace);
}

void	BitcoinExchange::validateDate(std::string &date)
{
	std::stringstream	ss(date);
	tm	my_time;

	// set date values
	ss >> my_time.tm_year;
	ss >> my_time.tm_mon;
	ss >> my_time.tm_mday;

	// adjust struct expectations
	my_time.tm_year -= 1900;
	my_time.tm_mon *= -1;
	my_time.tm_mon -= 1;
	my_time.tm_mday *= -1;

	tm	original = my_time;

	// normalize overflows or invalid values
	mktime(&my_time);

	// compare if mktime changed anything
	if (my_time.tm_year != original.tm_year ||my_time.tm_mon != original.tm_mon ||my_time.tm_mday != original.tm_mday)
		std::cout << RED << "invalid date" << RESET << "\n";
}
