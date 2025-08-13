/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:45:36 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/13 18:14:29 by huakbas          ###   ########.fr       */
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

const std::string	Bureaucrat::getName() const
{	return (this->_name);	}

int	Bureaucrat::getGrade() const
{	return (this->_grade);	}

void	Bureaucrat::promote()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::demote()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN2 << this->getName() << RESET
		<< " signed " << GREEN << form.getName() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
		std::cout << this->getName() << " couldn't sign " << form.getName()
		<< " because " << e.what() << std::endl;
	}
}

std::ostream& operator<< (std::ostream& o, Bureaucrat &b)
{
	o << GREEN2 << b.getName() << RESET << ", bureaucrat grade " << RED << b.getGrade() << RESET << ".";
	return (o);
}

const char*	Bureaucrat::GradeTooHighException::what () const throw ()
{
	return ("\e[1;3;31mBureaucrat::Exception: Grade is too high\e[0m");
}

const char*	Bureaucrat::GradeTooLowException::what () const throw ()
{
	return ("\e[1;3;31mBureaucrat::Exception: Grade is too low\e[0m");
}
