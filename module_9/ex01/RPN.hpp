/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:21:55 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/23 13:16:49 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <list>
#include <exception>
#include <limits>
#include <cmath>

#define	RED		"\e[1;31m"
#define	RESET	"\e[0m"

class	RPN
{
	private:
		std::stack<double, std::list<double> > numbers;
		void	trim(std::string &str);
		void	operate(char op);
		void	calculate(char op);
		void	errorCheck(std::string &input);

	public:
		RPN();
		~RPN();
		RPN(const RPN &RPN);
		RPN& operator=(const RPN &RPN);
		int	rpn(std::string input);

		class InvalidInputException : public std::exception {
			const char*	what() const throw () {
				return ("\e[1;31mInvalid Input\e[0m");
			}
		};
};

bool	isoperator(char ch);