#include "Contact.hpp"

void Contact::set_contact(
			std::string	first_name,
			std::string	last_name,
			std::string	nick_name,
			std::string	secret,
			std::string	phone_number
		)
{
	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nick_name = nick_name;
	this->_secret = secret;
	this->_phone_number = phone_number;
}

void	Contact::print_contact(int i)
{
	std::cout
	<< "|" << std::setw(10) << i
	<< "|" << std::setw(10) << this->get_first_name()
	<< "|" << std::setw(10) << this->get_last_name()
	<< "|" << std::setw(10) << this->get_nick_name()
	<< "|" << std::endl;
}

const std::string Contact::get_first_name()
{
	if (this->_first_name.length() <= 10)
		return (this->_first_name);
	else
		return (this->_first_name.substr(0,9) + ".");
}

const std::string Contact::get_last_name()
{
	if (this->_last_name.length() <= 10)
		return (this->_last_name);
	else
		return (this->_last_name.substr(0,9) + ".");
}

const std::string Contact::get_nick_name()
{
	if (this->_nick_name.length() <= 10)
		return (this->_nick_name);
	else
		return (this->_nick_name.substr(0,9) + ".");
}

const std::string Contact::get_secret()
{
	if (this->_secret.length() <= 10)
		return (this->_secret);
	else
		return (this->_secret.substr(0,9) + ".");
}

const std::string Contact::get_phone_number()
{
	if (this->_phone_number.length() <= 10)
		return (this->_phone_number);
	else
		return (this->_phone_number.substr(0,9) + ".");
}

void Contact::set_first_name(std::string first_name)
{
	this->_first_name = first_name;
}

void Contact::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
}

void Contact::set_nick_name(std::string nick_name)
{
	this->_nick_name = nick_name;
}

void Contact::set_secret(std::string secret)
{
	this->_secret = secret;
}

void Contact::set_phone_number(int phone_number)
{
	this->_phone_number = phone_number;
}