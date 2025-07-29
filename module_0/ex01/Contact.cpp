#include "Contact.hpp"


Contact::Contact (): _index(0) {}

void Contact::set_contact(
			int			index,
			std::string	first_name,
			std::string	last_name,
			std::string	nick_name,
			std::string	phone_number,
			std::string	secret
		)
{
	this->_index = index;
	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nick_name = nick_name;
	this->_phone_number = phone_number;
	this->_secret = secret;
}

void	Contact::print_contact()
{
	std::cout
	<< std::left << std::setw(11) << "Index" << " : " << this->get_index() << std::endl
	<< std::left << std::setw(11) << "First Name" << " : " << this->get_first_name() << std::endl
	<< std::left << std::setw(11) << "Last Name" << " : " << this->get_last_name() << std::endl
	<< std::left << std::setw(11) << "Nick Name" << " : " << this->get_nick_name() << std::endl
	<< std::left << std::setw(11) << "Phone" << " : " << this->get_phone_number() << std::endl
	<< std::left << std::setw(11) << "Secret" << " : " << this->get_secret() << std::endl;
}

void	Contact::print_contact_oneline()
{
	std::cout
	<< "|" << std::setw(10) << this->get_index()
	<< "|" << std::setw(10) << this->make_short(this->get_first_name())
	<< "|" << std::setw(10) << this->make_short(this->get_last_name())
	<< "|" << std::setw(10) << this->make_short(this->get_nick_name())
	<< "|" << std::endl;
}

const std::string Contact::make_short( std::string str)
{
	if (str.length() <= 10)
		return (str);
	else
		return (str.substr(0,9) + ".");
}

const std::string Contact::get_first_name()
{
	return (this->_first_name);
}

const std::string Contact::get_last_name()
{
	return (this->_last_name);
}

const std::string Contact::get_nick_name()
{
	return (this->_nick_name);
}

const std::string Contact::get_secret()
{
	return (this->_secret);
}

const std::string Contact::get_phone_number()
{
	return (this->_phone_number);
}

int Contact::get_index()
{
	return (this->_index);
}