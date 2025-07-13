#include "Contact.hpp"

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

int Contact::get_phone_number()
{
	return (this->_phone_number);
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