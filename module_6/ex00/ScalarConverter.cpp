/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:36 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:18:58 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &a)
{	*this = a;	}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &a)
{
	(void) a;
	return (*this);
}

bool	ScalarConverter::isChar(std::string input)
{
	return (input.length() == 1 && !std::isdigit(input[0]) && std::isprint(input[0]));
}

bool	ScalarConverter::isNumber(std::string input)
{
	int	points = 0;
	for (size_t i = 0; i < input.length(); i++)
	{
		while (input[i] == '-' || input[i] == '+')
			i++;
		if (input[i] == '.')
			points++;
		if ((!std::isdigit(input[i]) && input[i] != '.') || points > 1)
		{
			std::cout << "Bad input at index: " << i << std::endl;
			return (false);
		}
	}
	return (true);
}

void	ScalarConverter::convertToChar(std::string input)
{
	std::istringstream	ss(input);
	int	ch;
	ss >> ch;
	if (ss.fail() || ch > std::numeric_limits<char>::max() || ch < std::numeric_limits<char>::min())
		std::cout << RED << "char: impossible" << RESET << std::endl;
	else if (!std::isprint(ch))
		std::cout << YELLOW << "char: non displayable" << RESET << std::endl;
	else
		std::cout << "char: " << static_cast<char>(ch) << std::endl;
}

void	ScalarConverter::convertToInt(std::string input)
{
	double	numd;
	std::istringstream	ss(input);
	ss >> numd;
	if (ss.fail() ||numd > std::numeric_limits<int>::max() || numd < std::numeric_limits<int>::min())
		std::cout << RED << "int: impossible" << RESET << std::endl;
	else
		std::cout << "int: " << static_cast<int>(numd) << std::endl;
}

void	ScalarConverter::convertToFloat(std::string input)
{
	float	numf;
	std::istringstream	ss(input);
	ss >> numf;
	if (ss.fail())
		std::cout << RED << "float: impossible" << RESET << std::endl;
	else
		std::cout << std::fixed << "float: " << numf << std::endl;
}

void	ScalarConverter::convertToDouble(std::string input)
{
	double	numd;
	std::istringstream	ss(input);
	ss >> numd;
	if (ss.fail())
		std::cout << RED << "double: impossible" << RESET << std::endl;
	else
		std::cout << "double: " << std::fixed << numd << std::endl;
}

void	ScalarConverter::convert(std::string input)
{
	if (isChar(input))
	{
		std::ostringstream	ss;
		ss << static_cast<int>(input[0]);
		input = ss.str();
	}
	convertToChar(input);
	convertToInt(input);
	convertToFloat(input);
	convertToDouble(input);
}
