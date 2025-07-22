/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:29:53 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/22 13:51:52 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void	print_labels()
{
	std::cout
	<< "|" << std::setw(10) << "Index"
	<< "|" << std::setw(10) << "Firstname"
	<< "|" << std::setw(10) << "Lastname"
	<< "|" << std::setw(10) << "Nickname"
	<< "|" << std::endl;
}

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

void	add_contact(PhoneBook *book)
{
	std::string	input[5];
	int			i;

	std::cout << YELLOW << "ADD CONTACT:" << RESET << std::endl;
	if (book->get_index() + 1 > 7)
	{
		std::cout << WARN << "Warning: New contact will be replaced with contact: "
		<< ((book->get_index() + 1) % 8) << RESET << std::endl;
	}
	i = 0;
	while (i < 5)
	{
		std::cout << "Please enter " << fields[i] << " :" << std::endl;
		std::getline(std::cin, input[i]);
		if (i == 3 && !is_number(input[i]))
			continue ;
		if (input[i] != "")
			i++;
	}
	book->add_contact(input[0], input[1], input[2], input[3], input[4]);
}

void	print_all(PhoneBook book)
{
	print_labels();
	for (int i = 0; i < book.get_index() + 1; i++)
	{
		if (i == 8)
			return ;
		book.get_contact(i).print_contact(i);
	}
}

void	search_contact(PhoneBook book)
{
	std::string	index;

	index = "";
	std::cout << MAGENT << "SEARCH:" << RESET << std::endl;
	while (index.length() > 1 || index[0] > '7' || index[0] < '0')
	{
		if (index != "")
			std::cout << WARN << "Invalid index value!" << RESET << std::endl;
		std::cout << "Please enter index number (0-7):" << std::endl;
		std::getline(std::cin, index);
		if (index == "-1")
		{
			if (book.get_contact(0).get_first_name() != "")
				print_all(book);
			else
				std::cout << WARN << "There is no contact recorded yet!" << RESET << std::endl;
			return ;
		}
	}
	if (index[0] - 48 > book.get_index())
		std::cout << GREEN << "Contact is empty: \e[3m" << RESET << index << std::endl;
	else
	{
		print_labels();
		book.get_contact(index[0] - 48).print_contact(index[0] - 48);
	}
}

void	print_options()
{
	std::cout << CYAN << "\e[4m" << "Please select an option (1,2,3):" << RESET << std::endl
	<< YELLOW << " (1): ADD CONTACT - "
	<< MAGENT << "(2): SEARCH - "
	<<  RED  << "(3): EXIT "
	<< RESET << std::endl;
}

int	main()
{
	PhoneBook	book;
	std::string	select;

	std::cout << "\e[1;91;106m" << " WELCOME TO THE GREATEST PHONEBOOK EVER " << RESET << std::endl;
	while (1)
	{
		print_options();
		std::getline(std::cin, select);
		if (select == "1")
			add_contact(&book);
		else if (select == "2")
			search_contact(book);
		else if (select == "3")
		{
			std::cout << BLUE << "Good Bye" << RESET << std::endl;
			return (0);
		}
		else
			std::cout << WARN << "INVALID OPTION" << std::endl;
	}
	return (0);
}
