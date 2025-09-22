/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:21:52 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/22 17:11:35 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other)
{
	if (this == &other)
		return ;
	*this = other;
}

RPN&	RPN::operator=(const RPN& other)
{
	if (this == &other)
		return (*this);
	this->numbers = other.numbers;
	return (*this);
}

void	RPN::trim(std::string &str)
{
	str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}

bool	isoperator(char ch)
{
	std::string	operators = "+-*/";
	if (operators.find(ch) != std::string::npos)
		return (true);
	return (false);
}

void	RPN::operate(char op)
{
	double	operand2 = this->numbers.top();
	this->numbers.pop();
	double operand = this->numbers.top();
	this->numbers.pop();

	//	COMMENT OUT TO SEE CALCULATION STEP BY STEP
	//std::cout << RED << operand << " " << op << " " << operand2 << "\n" << RESET;

	switch (op)
	{
	case '+':
		this->numbers.push(operand + operand2);
		break;
	case '-':
		this->numbers.push(operand - operand2);
		break;
	case '*':
		this->numbers.push(operand * operand2);
		break;
	case '/':
		this->numbers.push(operand / operand2);
		break;
	default:
		break;
	}
}

void	RPN::calculate(char op)
{
	if (isdigit(op))
		this->numbers.push(op - 48);
	else if (this->numbers.size() < 2)
	{
		std::cerr << RED << "Error: not enough numbers to calculate before operator!\n" << RESET;
		throw InvalidInputException();
	}
	else
		operate(op);
}

void	RPN::errorCheck(std::string &input)
{
	if (input.empty())
		throw InvalidInputException();

	// check invalid characters
	if (input.find_first_not_of("1234567890+-*/ ") != std::string::npos)
	{
		std::cerr << RED << "Error: Invalid char in sequence: " << RESET
		<< input[input.find_first_not_of("1234567890+-*/ ")] <<"\n";
		throw InvalidInputException();
	}

	for(std::string::iterator it = input.begin(); (it + 1) != input.end(); ++it)
	{
		if (std::isdigit(*it) && std::isdigit(*(it + 1)))
		{
			if (*it == '0')
				*it = ' ';
			else
			{
				std::cerr << RED << "Error: number is too big" << RESET <<"\n";
				throw InvalidInputException();
			}
		}
	}

	this->trim(input);
	if (input.empty())
		throw InvalidInputException();
	// check digits and operators count
	if (std::count_if(input.begin(), input.end(), isdigit) != std::count_if(input.begin(), input.end(), isoperator) + 1)
	{
		std::cerr << RED << "Error: Digit count must be one greater than operator count\n" << RESET;
		throw InvalidInputException();
	}
}

void	RPN::rpn(std::string input)
{
	// check errors
	try
	{
		errorCheck(input);
		// iterator applies function to all chars one by one
		for (std::string::iterator i = input.begin(); i < input.end(); i++)
			this->calculate(*i);
		// print output
		std::cout << numbers.top() << "\n";
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
}
