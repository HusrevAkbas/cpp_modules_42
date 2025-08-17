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
	double	ch;
	ss >> ch;
	if (ss.fail() || ch > std::numeric_limits<char>::max() || ch < 0)
		std::cout << RED << "char: impossible" << RESET << std::endl;
	else if (!std::isprint(ch))
		std::cout << YELLOW << "char: non displayable" << RESET << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(ch) << "'" << std::endl;
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

	if (input == "inf" || input == "+inf")
		numf = static_cast<float>(std::numeric_limits<double>::infinity());
	else if (input == "inff" || input == "+inff")
		numf = std::numeric_limits<float>::infinity();
	else if (input == "-inf")
		numf = static_cast<float>(-std::numeric_limits<double>::infinity());
	else if (input == "-inff")
		numf = -std::numeric_limits<float>::infinity();
	else if (input == "nan")
		numf = static_cast<float>(std::numeric_limits<double>::quiet_NaN());
	else if (input == "nanf")
		numf = std::numeric_limits<float>::quiet_NaN();
	else
		ss >> numf;
	if (ss.fail())
		std::cout << RED << "float: impossible" << RESET << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << numf << "f" << std::endl;
}

void	ScalarConverter::convertToDouble(std::string input)
{
	double	numd;
	std::istringstream	ss(input);

	if (input == "inf" || input == "+inf")
		numd = std::numeric_limits<double>::infinity();
	else if (input == "inff" || input == "+inff")
		numd = static_cast<double>(std::numeric_limits<float>::infinity());
	else if (input == "-inf")
		numd = -std::numeric_limits<double>::infinity();
	else if (input == "-inff")
		numd = static_cast<double>(-std::numeric_limits<float>::infinity());
	else if (input == "nanf")
		numd = static_cast<double>(std::numeric_limits<float>::quiet_NaN());
	else if (input == "nan")
		numd = std::numeric_limits<double>::quiet_NaN();
	else
		ss >> numd;
	if (ss.fail())
		std::cout << RED << "double: impossible" << RESET << std::endl;
	else
		std::cout << "double: " << std::setprecision(1) << std::fixed << numd << std::endl;
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
