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
	try
	{
		getData();
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
}

BitcoinExchange::BitcoinExchange(std::string db_file)
: _db_filename(db_file)
{
	try
	{
		getData();
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
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
		throw DatabaseErrorException();
	}

	std::getline(input_file, line);	// skip titles
	if (input_file.eof())
	{
		std::cerr << RED << "Database is empty!\n" << RESET;
		throw DatabaseErrorException();
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
			throw DatabaseErrorException();
		}
		value = line.substr(index_delimiter + 1);
		value_d = validateValue(value);
		if (value_d < 0)
		{
			std::cerr << RED << value << " " << value_d << " Invalid value in database! Abort...\n" << RESET;
			throw DatabaseErrorException();
		}
		// save time_t for days, ignore hours and smaller units, divide by SECS_PER_DAY
		the_time = the_time / SECS_PER_DAY;

		std::map<time_t, double>::iterator it = this->_data.find(the_time);
		if (it == this->_data.end())
			this->_data.insert(std::pair<time_t, double>(the_time, value_d));
		else
		{
			std::cerr << YELLOW << "Warning: duplicate date in database, value is updated\n"
			<< date << " old value: " << it->second << " new value: " << value_d << "\n" << RESET;
			it->second = value_d;
		}

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

	if (std::count(date.begin() + 1, date.end(), '-') > 2)
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

bool	BitcoinExchange::databaseReady()
{
	return (this->_data.size() > 0);
}

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

void	BitcoinExchange::calculateExchange(std::string filename)
{
	// read input file
	std::fstream	inputFile(filename.c_str(), std::fstream::in);
	if (!inputFile)
	{
		std::cerr << RED << "Failed to open input file\n" << RESET;
		return ;
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
		date_time = this->validateDate(date);
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
		value_d = this->validateValue(value);
		if (value_d > 1000)
			value_d = -2;
		if (value_d < 0)
		{
			printValueError(value_d);
			title_pass = true;
			continue ;
		}

		// find currency in database
		double	btc_value = this->getValue(date_time / SECS_PER_DAY);
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
}
