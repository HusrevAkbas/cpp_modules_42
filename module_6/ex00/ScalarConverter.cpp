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

int	ScalarConverter::getType(std::string input)
{
	size_t	has_e = 0;
	size_t	has_f = 0;
	size_t	has_sign = 0;
	// check invalid chars
	if (input.find_first_not_of("0123456789-+ef") != std::string::npos)
		return (0);
	// check char
	if (input.length() == 0 && !std::isdigit(input[0])) // && std::isprint(input[0]))
		return (1);
	// check sign
	has_sign = input.find_first_of("+-", 1);
	if (has_sign != std::string::npos && input[has_sign - 1] != 'e')
		return (0);
	// check signtific notation
	has_e = input.find("e");
	if (has_e != std::string::npos)
	{
		if (has_e == input.length() - 1)
			return (0);
		if (!std::isdigit(input[has_e + 1]) && input[has_e + 1] != '+' && input[has_e + 1] != '-')
			return (0);
	}
	// check float suffix
	has_f = input.find("f");
	if (has_f == input.length() - 1)
		return (3);
	if (has_f != std::string::npos)
		return (0);
	if (has_e != std::string::npos)
		return (4);
	// check int
	double	numd;
	std::istringstream	ss(input);
	ss >> numd;
	if (ss.fail())
		return (0);
	if (numd <= std::numeric_limits<int>::max() && numd >= std::numeric_limits<int>::min())
		return (2);
	return (4);
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
	int	numd;
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
		std::cout << std::fixed << "float: " << numf << "f" << std::endl;
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
		std::cout << "double: " << std::fixed << numd << std::endl;
}

void	ScalarConverter::convert(std::string input)
{
	int	type;

	type = getType(input);
	std::cout << MAGENT << type << std::endl;
	convertToChar(input);
	convertToInt(input);
	convertToFloat(input);
	convertToDouble(input);
}
