/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:44:42 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/09/15 17:28:26 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <stack>

#define	RED		"\e[1;31m"
#define	RESET	"\e[0m"

void	trim(std::string &str)
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

void	operate(char op, std::stack<double> *numbers)
{
	double	operand2 = numbers->top();
	numbers->pop();
	double operand = numbers->top();
	numbers->pop();

	//	COMMENT OUT TO SEE CALCULATION STEP BY STEP
	//std::cout << RED << operand << " " << op << " " << operand2 << "\n" << RESET;

	switch (op)
	{
	case '+':
		numbers->push(operand + operand2);
		break;
	case '-':
		numbers->push(operand - operand2);
		break;
	case '*':
		numbers->push(operand * operand2);
		break;
	case '/':
		numbers->push(operand / operand2);
		break;
	default:
		break;
	}
}

void	calculate(char op, std::stack<double>	*numbers)
{
	if (isdigit(op))
		numbers->push(op - 48);
	else if (numbers->size() < 2)
	{
		std::cerr << RED << "Error: not enough numbers to calculate before operator!\n" << RESET;
		exit(4);
	}
	else
		operate(op, numbers);
}

int	main(int argc, char **argv)
{

	std::stack<double>	numbers;
	
	if (argc != 2)
	{
		std::cerr << RED << "Error: Program takes only one argument in quotes:\n" << RESET;
		std::cout << "./RPN \"1 2 3 + -\"";
		return (1);
	}

	std::string	input = argv[1];
	
	// check invalid characters
	if (input.find_first_not_of("1234567890+-*/ ") != std::string::npos)
	{
		std::cerr << RED << "Error: Invalid char in sequence: " << RESET
		<< input[input.find_first_not_of("1234567890+-*/")] <<"\n";
		return (2);
	}

	for(std::string::iterator it = input.begin(); (it + 1) != input.end(); ++it)
	{
		if (std::isdigit(*it) && std::isdigit(*(it + 1)))
		{
			std::cerr << RED << "Error: number is too big" << RESET
			<< input[input.find_first_not_of("1234567890+-*/")] <<"\n";
			return (3);
		}
	}

	trim(input);
	// check digits and operators count
	if (std::count_if(input.begin(), input.end(), isdigit) != std::count_if(input.begin(), input.end(), isoperator) + 1)
	{
		std::cerr << RED << "Error: Digit count must be one greater than operator count\n" << RESET;
		return (3);
	}

	// iterator applies function to all chars one by one
	for (std::string::iterator i = input.begin(); i < input.end(); i++)
		calculate(*i, &numbers);

	// print output
	std::cout << numbers.top() << "\n";
	return (0);
}
