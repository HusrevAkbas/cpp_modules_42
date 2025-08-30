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

#define	RED		"\e[1;31m"
#define	RESET	"\e[0m"

class BitcoinExchange
{
	private:
		std::map<double, double>	_data;
		std::string					_db_filename;
		void	getData();
		static void	trim(std::string &str);
		void	validateDate(std::string &date);
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(std::string data_file);
		BitcoinExchange(const BitcoinExchange &a);
		BitcoinExchange& operator=(const BitcoinExchange &a);
};
