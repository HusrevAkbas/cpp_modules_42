/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:21:37 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/14 19:04:26 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	for (int i = 0; i < 8; i++)
		this->_contacts[i] = Contact();
	this->_index = 0;
}

void PhoneBook::add_contact(
			std::string	first_name,
			std::string	last_name,
			std::string	nick_name,
			std::string	secret,
			std::string	phone_number
)
{
	this->_contacts[this->_index % 8].set_contact(
		first_name, last_name, nick_name, secret, phone_number
	);
	this->_index++;
}

Contact	PhoneBook::get_contact(int i)
{
	return (this->_contacts[i % 8]);
}
int	PhoneBook::get_index()
{
	return (this->_index - 1);
}
