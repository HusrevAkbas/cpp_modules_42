/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:29:53 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/29 15:36:16 by huakbas          ###   ########.fr       */
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

int	add_contact(PhoneBook *book)
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
		if (std::cin.eof())
			return (-1);
		if (i == 3 && !is_number(input[i]))
			continue ;
		if (input[i] != "")
			i++;
	}
	book->add_contact(input[0], input[1], input[2], input[3], input[4]);
	return (0);
}

int	search_contact(PhoneBook book)
{
	std::string	index;

	std::cout << MAGENT << "SEARCH:" << RESET << std::endl;
	if (book.get_index() == -1)
	{
		std::cout << WARN << "There is no contact yet" << RESET << std::endl;
		return (0);
	}
	book.print_contact_list();
	index = "";
	while (index.length() > 1 || index[0] > '7' || index[0] < '0')
	{
		if (index != "")
			std::cout << WARN << "Invalid index value!" << RESET << std::endl;
		std::cout << "Please enter index number (0-7):" << std::endl;
		std::getline(std::cin, index);
		if (std::cin.eof())
			return (1);
	}
	if (index[0] - 48 > book.get_index())
		std::cout << GREEN << "Contact is empty: \e[3m" << RESET << index << std::endl;
	else
		book.get_contact(index[0] - 48).print_contact();
	return (0);
}

void	print_options()
{
	std::cout 
	<< YELLOW << " ADD - "
	<< MAGENT << "SEARCH - "
	<<  RED  << " EXIT " << std::endl
	<< CYAN << "\e[4m" << "Please select an option: " << RESET
	<< RESET;
}

int	main()
{
	PhoneBook	book;
	std::string	select;
	int			eof;

	eof = 0;
	std::cout << "\e[1;91;106m" << " WELCOME TO THE GREATEST PHONEBOOK EVER " << RESET << std::endl;
	while (1)
	{
		select = "4";
		print_options();
		std::getline(std::cin, select);
		if (select == "ADD")
			eof = add_contact(&book);
		else if (select == "SEARCH")
			eof = search_contact(book);
		else if (select != "EXIT" && !std::cin.eof())
			std::cout << WARN << "INVALID OPTION" << RESET << std::endl;
		if (eof || std::cin.eof() || select == "EXIT")
		{
			if (std::cin.eof())
				std::cout << std::endl;
			std::cout << BLUE << "Good Bye" << RESET << std::endl;
			return (0);
		}
	}
	return (0);
}
