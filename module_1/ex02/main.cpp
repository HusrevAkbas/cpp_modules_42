/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 23:12:07 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 12:17:56 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	string;
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	string = "HI THIS IS BRAIN";

	std::cout << std::endl << "Memory of address of string: " << &string << std::endl;
	std::cout << "Memory of address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory of address of stringREF: " << &stringREF << std::endl;
	
	std::cout << std::endl << "Value of address of string: " << string << std::endl;
	std::cout << "Value of address of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of address of stringREF: " << stringREF << std::endl;
	
	string = "HI THIS IS NOT A BRAIN";

	std::cout << std::endl << "Memory of address of string: " << &string << std::endl;
	std::cout << "Memory of address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory of address of stringREF: " << &stringREF << std::endl;
	
	std::cout << std::endl << "Value of address of string: " << string << std::endl;
	std::cout << "Value of address of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of address of stringREF: " << stringREF << std::endl;

	return (0);
}
