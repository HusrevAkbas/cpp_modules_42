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
	size_t	points = 0;
	size_t	has_e = 0;
	size_t	has_f = 0;
	size_t	has_sign = 0;
	// check char
	if (input.length() == 1 && !std::isdigit(input[0])) // && std::isprint(input[0]))
		return (1);
	// check invalid chars
	if (input.find_first_not_of("0123456789-+ef.") != std::string::npos)
		return (0);
	for (size_t i = 0; i < input.length(); i++)
	{
		if (has_f)
			return (0);
		if (input[i] == 'e')
			has_e++;
		if (input[i] == '.')
			points++;
		if (input[i] == 'f')
			has_f++;
		if (has_e > 1 || points > 1)
			return (0);
	}
	// check sign
	has_sign = input.find_first_of("+-", 1);
	if (has_sign != std::string::npos && input[has_sign - 1] != 'e')
		return (0);
	// check float suffix
	if (has_f)
		return (3);
	if (has_e || points)
		return (4);
	// check int
	int	numd;
	std::istringstream	ss(input);
	ss >> numd;
	if (ss.fail())
		return (4);
	return (2);
}

void	ScalarConverter::convertChar(char input)
{
	if (!std::isprint(input))
		std::cout << YELLOW << "char: non displayable" << RESET << std::endl;
	else
		std::cout << "char: '" << input << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << std::fixed << static_cast<float>(input) << "f" << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(input) << std::endl;
}

void	ScalarConverter::convertInt(int input)
{
	if (input > std::numeric_limits<char>::max() || input < 0)
		std::cout << RED << "char: impossible" << RESET << std::endl;
	else if (!std::isprint(static_cast<char>(input)))
		std::cout << YELLOW << "char: non displayable" << RESET << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(input) << "'" << std::endl;
	std::cout << "int: " << input << std::endl;
	std::cout << "float: " << std::fixed << static_cast<float>(input) << "f" << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(input) << std::endl;
}

void	ScalarConverter::convertFloat(float input)
{
	if (input > std::numeric_limits<char>::max() || input < 0)
		std::cout << RED << "char: impossible" << RESET << std::endl;
	else if (!std::isprint(static_cast<char>(input)))
		std::cout << YELLOW << "char: non displayable" << RESET << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(input) << "'" << std::endl;
	if (input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::min())
		std::cout << RED << "int: impossible" << RESET << std::endl;
	else
		std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << std::fixed << input << "f" << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(input) << std::endl;
}

void	ScalarConverter::convertDouble(double input)
{
	if (input > std::numeric_limits<char>::max() || input < 0)
		std::cout << RED << "char: impossible" << RESET << std::endl;
	else if (!std::isprint(static_cast<char>(input)))
		std::cout << YELLOW << "char: non displayable" << RESET << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(input) << "'" << std::endl;
	if (input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::min())
		std::cout << RED << "int: impossible" << RESET << std::endl;
	else
		std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << std::fixed << static_cast<float>(input) << "f" << std::endl;
	std::cout << "double: " << std::fixed << input << std::endl;
}

void	ScalarConverter::convert(std::string input)
{
	int	type;
	std::istringstream	ss(input);

	type = getType(input);
	std::cout << MAGENT << type << RESET << std::endl;
	switch (type)
	{
	case 0:
		std::cout << RED << "Impossible to convert" << RESET << std::endl;
		break;
	case 1:
		ScalarConverter::convertChar(input[0]);
		break;
	case 2:
		int	num;
		ss >> num;
		ScalarConverter::convertInt(num);
		break;
	case 3:
		float	numf;
		ss >> numf;
		if (ss.fail())
		{
			std::cout << RED << "Impossible to convert" << RESET << std::endl;
			return ;
		}
		ScalarConverter::convertFloat(numf);
		break;
	case 4:
		double	numd;
		ss >> numd;
		if (ss.fail())
		{
			std::cout << RED << "Impossible to convert" << RESET << std::endl;
			return ;
		}
		ScalarConverter::convertDouble(numd);
		break;
	default:
		break;
	}
}
