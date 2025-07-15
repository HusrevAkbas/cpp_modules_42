/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 23:12:07 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/15 23:26:05 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	string;
	std::string	*stringPTR;
	std::string	&stringREF = string;

	stringPTR = &string;
	string = "HI THIS IS BRAIN";

	std::cout << "Memory of address of string: " << &string << std::endl;
	std::cout << "Memory of address of string: " << &stringPTR << std::endl;
	std::cout << "Memory of address of string: " << &stringREF << std::endl;
	
	std::cout << "Value of address of string: " << string << std::endl;
	std::cout << "Value of address of string: " << *stringPTR << std::endl;
	std::cout << "Value of address of string: " << stringREF << std::endl;

	return (0);
}
