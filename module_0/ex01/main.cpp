/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:29:53 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/14 19:05:56 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

bool	is_number(std::string str)
{
	int	i;

	i = 0;
	if (str[0] == '+')
		i = 1;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	main()
{
	PhoneBook	book;
	std::string	select;
	std::string	input[5];
	std::string	index;
	int			i;

	while (1)
	{
		index = "";
		std::cout << "Please select an option (1,2,3):" << std::endl
		<< YELLOW << " (1): ADD CONTACT - "
		<< MAGENT << "(2): SEARCH - "
		<<  RED   << "(3): EXIT " << book.get_index()
		<< RESET  << std::endl;
		std::getline(std::cin, select);
		if (select == "1")
		{
			std::cout << YELLOW << "ADD CONTACT:" << RESET << std::endl;
			i = 0;
			while (i < 5)
			{
				std::cout << "Please enter " << fields[i] << " :" << std::endl;
				std::getline(std::cin, input[i]);
				if (i == 4 && !is_number(input[i]))
					continue ;
				if (input[i] != "")
					i++;
			}
			book.add_contact(input[0], input[1], input[2], input[3], input[4]);
		}
		else if (select == "2")
		{
			std::cout << MAGENT << "SEARCH:" << RESET << std::endl;
			while (index.length() == 0 || index.length() > 1 || index[0] > '7')
			{
				std::cout << "Please enter index number (0-7):" << std::endl;
				std::getline(std::cin, index);
			}
			if (index[0] - 48 > book.get_index())
				std::cout << GREEN << "Contact is empty: \e[3m" << RESET << index << std::endl;
			else
				book.get_contact(index[0] - 48).print_contact(index[0] - 48);
		}
		else if (select == "3")
		{
			std::cout << RED << "Good Bye" << RESET << std::endl;
			return (0);
		}
		else
			std::cout << "INVALID OPTION" << std::endl;
	}
	return (0);
}
