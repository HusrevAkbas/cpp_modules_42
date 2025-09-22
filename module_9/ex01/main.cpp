/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:44:42 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/09/22 16:58:11 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{

	std::stack<double, std::list<double> >	numbers;

	if (argc != 2)
	{
		std::cerr << RED << "Error: Program takes only one argument in quotes:\n" << RESET;
		std::cout << "./RPN \"1 2 3 + -\"";
		return (1);
	}

	RPN	calculator;

	calculator.rpn(argv[1]);

	return (0);
}
