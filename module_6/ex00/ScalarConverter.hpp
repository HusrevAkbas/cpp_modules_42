/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:41 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:11:15 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <limits>
#include <limits.h>
#include <cmath>
#include <iomanip>

#define RED	"\e[1;31m"
#define WARN	"\e[2;3;91m"
#define WARN2	"\e[2;3;92m"
#define WARN3	"\e[2;3;93m"
#define WARN4	"\e[2;3;94m"
#define GREEN	"\e[1;32m"
#define YELLOW	"\e[1;33m"
#define BLUE	"\e[1;34m"
#define MAGENT	"\e[1;35m"
#define CYAN	"\e[1;36m"
#define GRAY	"\e[1;90m"
#define BG		"\e[1;105m"
#define RESET	"\e[0m"

class ScalarConverter
{
	private:
		static int	getType(std::string input);
		static void	convertToChar(std::string input);
		static void	convertToInt(std::string input);
		static void	convertToFloat(std::string input);
		static void	convertToDouble(std::string input);
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &a);
		ScalarConverter& operator=(const ScalarConverter &a);
		static void	convert(std::string input);
};
