/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:21:37 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/29 15:24:48 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	for (int i = 0; i < 8; i++)
		this->_contacts[i] = Contact();
	this->_index = -1;
}

void PhoneBook::add_contact(
			std::string	first_name,
			std::string	last_name,
			std::string	nick_name,
			std::string	secret,
			std::string	phone_number
)
{
	this->_index++;
	this->_contacts[this->_index % 8].set_contact(
		this->get_index() % 8, first_name, last_name, nick_name, secret, phone_number
	);
}

Contact	PhoneBook::get_contact(int i)
{
	return (this->_contacts[i % 8]);
}
int	PhoneBook::get_index()
{
	return (this->_index);
}
void	PhoneBook::print_contact_list()
{
	std::cout
	<< "|" << std::setw(10) << "Index"
	<< "|" << std::setw(10) << "Firstname"
	<< "|" << std::setw(10) << "Lastname"
	<< "|" << std::setw(10) << "Nickname"
	<< "|" << std::endl;
	for (size_t i = 0; i < 8 && (int)i <= this->get_index(); i++)
		this->get_contact(i).print_contact_oneline();

}
