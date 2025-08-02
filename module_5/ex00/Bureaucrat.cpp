/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:45:36 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/02 16:58:24 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("DEFAULT"), _grade (150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat &a)
{	*this = a;	}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &a)
{
	this->_grade = a._grade;
	return (*this);
}

const std::string	Bureaucrat::getName()
{	return (this->_name);	}

int	Bureaucrat::getGrade()
{	return (this->_grade);	}

std::ostream& operator<< (std::ostream& o, Bureaucrat &b)
{
	o << GREEN << b.getName() << RESET << ", bureaucrat grade " << RED << b.getGrade() << RESET << ".";
	return (o);
}

const char*	Bureaucrat::GradeTooHighException::what () const throw ()
{
	return ("\e[1;3;35mException: Grade is too high\e[0m");
}

const char*	Bureaucrat::GradeTooLowException::what () const throw ()
{
	return ("\e[1;3;34mException: Grade is too low\e[0m");
}
