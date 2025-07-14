/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:29:53 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/14 15:03:35 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

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
		std::cout << "Please select an option:" << std::endl
		<< "1: ADD CONTACT" << std::endl
		<< "2: SEARCH" << std::endl
		<< "3: EXIT" << std::endl;
		std::getline(std::cin, select);
		if (select == "1")
		{
			std::cout << "ADD CONTACT" << std::endl;
			i = 0;
			while (i < 5)
			{
				std::cout << "Please enter " << fields[i] << " :" << std::endl;
				std::getline(std::cin, input[i]);
				if (input[i] != "")
					i++;
			}
			book.add_contact(input[0], input[1], input[2], input[3], input[4]);
		}
		else if (select == "2")
		{
			std::cout << "SEARCH:" << std::endl;
			while (index.length() == 0 || index.length() > 1 || index == "9")
			{
				std::cout << "Please enter index number (0-7):" << std::endl;
				std::getline(std::cin, index);
			}
			if (index[0] - 48 > book.get_index())
				std::cout << index << " contact is empty" << std::endl;
			else
				book.get_contact(index[0] - 48).print_contact(index[0] - 48);
		}
		else if (select == "3")
		{
			std::cout << "Good Bye" << std::endl;
			return (0);
		}
		else
			std::cout << "INVALID OPTION" << std::endl;
			
	}
	return (0);
}
