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

BitcoinExchange::BitcoinExchange(std::string db_file)
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
	time_t			the_time;
	size_t			index_delimiter;
	double			value_d;

	if (!input_file)
	{
		std::cerr << RED << "Database couldn't found!\n" << RESET;
		exit(1);
	}

	std::getline(input_file, line);	// skip titles
	if (input_file.eof())
	{
		std::cerr << RED << "Database is empty!\n" << RESET;
		exit(2);
	}
	std::getline(input_file, line);
	while (!input_file.eof())
	{
		BitcoinExchange::trim(line);
		index_delimiter = line.find(",");
		date = line.substr(0, index_delimiter);
		the_time = validateDate(date);
		if (!the_time)
		{
			std::cerr << date << RED << "Invalid date in database! Abort..." << RESET << "\n";
			exit(3);
		}
		value = line.substr(index_delimiter + 1);
		value_d = validateValue(value);
		if (value_d < 0)
		{
			std::cerr << RED << value << " " << value_d << " Invalid value in database! Abort...\n" << RESET;
			exit(4);
		}
		// save time_t for days, ignore hours and smaller units, divide by SECS_PER_DAY
		this->_data.insert(std::pair<time_t, double>(the_time / SECS_PER_DAY, value_d));
		std::getline(input_file, line);
	}

	// print map values TEST ONLY
	// for (std::map<time_t, double>::iterator i = this->_data.begin(); i != this->_data.end(); i++)
	// {
	// 	std::cout << (*i).first << " "<< std::fixed << (*i).second << "\n";
	// }
}

time_t	BitcoinExchange::validateDate(std::string &date)
{

	if (date.find_last_not_of("1234567890- ") != std::string::npos)
		return (0);

	if (date[4] != '-' || date[7] != '-')
		return (0);

	std::stringstream	ss(date);
	tm	*my_time;
	time_t	the_time;

	// get rid of valgrind uninitialized value error 
	// inits all values in tm with current time
	time(&the_time);
	my_time = gmtime(&the_time);

	// set date values
	ss >> my_time->tm_year;
	ss >> my_time->tm_mon;
	ss >> my_time->tm_mday;

	// adjust struct expectations
	my_time->tm_year -= 1900;
	my_time->tm_mon *= -1;
	my_time->tm_mon -= 1;
	my_time->tm_mday *= -1;

	tm	original = *my_time;

	// normalize overflows or invalid values
	the_time = mktime(my_time);

	// compare if mktime changed anything
	if (my_time->tm_year != original.tm_year
		|| my_time->tm_mon != original.tm_mon
		||my_time->tm_mday != original.tm_mday)
			return (0);
	return (the_time);
}


double	BitcoinExchange::validateValue(std::string &value)
{
	std::stringstream	ss(value);
	double	num;

	// TODO	work on trim if value is " -1"
	if (value.find_first_not_of("1234567890. -") != std::string::npos
		|| value.find("-", 1) != std::string::npos )
		return (-1);
	if (std::count(value.begin(), value.end(), '.') > 1)
		return (-1);
	ss >> num;
	if (ss.fail())
		return (-1);
	if (num > std::numeric_limits<int>::max())
		return (-2);
	if (num < 0)
		return (-3);
	return (num);
}


double	BitcoinExchange::getValue(time_t const	time) const
{
	// if date is earlier than the begin date
	if (time < this->_data.begin()->first)
		return (-1);
	std::map<time_t, double>::const_iterator it = this->_data.upper_bound(time);
	// if the date doesnt match find previous date
	if (it == this->_data.end() || (it->second != time && it != this->_data.begin()))
		it--;
	return ((*it).second);
}

void	BitcoinExchange::trim(std::string &str)
{
	// std::remove_if(str.begin(), str.end(), isspace);
	// std::replace(str.begin(), str.end(), ' ', '');
	str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}
