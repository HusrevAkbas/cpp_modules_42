/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:41 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:11:15 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <ctime>
#include <iterator>
#include <limits>
#include <exception>

#define	RED		"\e[1;31m"
#define	YELLOW	"\e[1;33m"
#define	RESET	"\e[0m"

const time_t	SECS_PER_DAY = 24 * 60 * 60;

class BitcoinExchange
{
	private:
		std::map<time_t, double>	_data;
		std::string					_db_filename;
		void		getData();
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(std::string data_file);
		BitcoinExchange(const BitcoinExchange &a);
		BitcoinExchange& operator=(const BitcoinExchange &a);
		time_t		validateDate(std::string &date);
		double		validateValue(std::string &value);
		double		getValue(time_t	time) const;
		bool		databaseReady();
		void		calculateExchange(std::string filename);
		static void		trim(std::string &str);

		class DatabaseErrorException : public std::exception {
			const char *what () const throw () {
				return "\e[1;31mDatabase Error\e[0m";
			}
		};
};
