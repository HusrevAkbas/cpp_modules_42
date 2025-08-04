/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 23:12:07 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/04 12:45:39 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define GREEN	"\e[1;32m"
#define RESET	"\e[0m"

void	test1(std::string	string)
{
	std::cout << std::endl << "Memory of address of string: " << &string << std::endl;
	std::cout << "Value of address of string: " << string << std::endl;
	string = "NEW BRAIN";
	std::cout << "Memory of address of string: " << &string << std::endl;
	std::cout << "Value of address of string: " << string << std::endl;
}

void	test2(std::string	*string)
{
	std::cout << std::endl << "Memory of address of string: " << string << std::endl;
	std::cout << "Value of address of string: " << *string << std::endl;
	*string = "NEW BRAIN";
	std::cout << "Memory of address of string: " << string << std::endl;
	std::cout << "Value of address of string: " << *string << std::endl;
}

void	test3(std::string	&string)
{
	std::cout << std::endl << "Memory of address of string: " << &string << std::endl;
	std::cout << "Value of address of string: " << string << std::endl;
	string = "NEW BRAIN";
	std::cout << "Memory of address of string: " << &string << std::endl;
	std::cout << "Value of address of string: " << string << std::endl;
}
/*
	you can not reassign a reference type
*/

int	main()
{
	std::string	string;
	std::string	*stringPTR = &string;
	std::string	&stringREF = string; // *(stringPTR);

	string = "HI THIS IS BRAIN";

	std::cout << GREEN << std::endl << "Memory of address of string: " << &string << std::endl;
	std::cout << "Memory of address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory of address of stringREF: " << &stringREF << std::endl;
	
	std::cout << std::endl << "Value of address of string: " << string << std::endl;
	std::cout << "Value of address of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of address of stringREF: " << stringREF << RESET << std::endl;

	// test1(string);

	// test2(stringPTR);

	// test3(stringREF);

	// test4
	// std::string	string2 = "NEW BRAIN";
	// stringPTR = &string2;
	// stringREF = string2;
	// string2 = "BRAND NEW BRAIN";

	std::cout << GREEN << std::endl << "Memory of address of string: " << &string << std::endl;
	std::cout << "Memory of address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory of address of stringREF: " << &stringREF << std::endl;
	
	std::cout << std::endl << "Value of address of string: " << string << std::endl;
	std::cout << "Value of address of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of address of stringREF: " << stringREF << RESET << std::endl;

	return (0);
}
