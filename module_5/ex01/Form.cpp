/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:36 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:18:58 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
	_name("Default"),
	_signed(false),
	_grade_to_sign(22),
	_grade_to_execute(11)
{}

Form::Form( std::string name, int grade_to_sign, int grade_to_execute ) :
	_name(name),
	_signed(false),
	_grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute)
{
	if (_grade_to_execute < 1 || _grade_to_sign < 1)
		throw Form::GradeTooHighException();
	if (_grade_to_execute > 150 || _grade_to_sign > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(){}

Form::Form(const Form &a) :
	_name(a._name),
	_signed(a._signed),
	_grade_to_sign(a._grade_to_sign),
	_grade_to_execute(a._grade_to_execute)
{}

Form& Form::operator=(const Form &a)
{
	this->_signed = a._signed;
	return (*this);
}

const std::string	Form::getName()
{	return (this->_name);	}

int	Form::getGradeToExecute()
{	return (this->_grade_to_execute);	}

int	Form::getGradeToSign()
{	return (this->_grade_to_sign);	}

bool	Form::isSigned()
{	return (this->_signed);	}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeToSign())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<< (std::ostream &o, Form &b)
{
	o << "Form: " << GREEN << b.getName() << RESET
	<< (b.isSigned() ? "\e[34m (signed)" : "\e[35m (not signed)") << RESET
	<< ", grade to sign: " << YELLOW << b.getGradeToSign() << RESET
	<< ", grade to execute: " << CYAN << b.getGradeToExecute() << RESET;
	return (o);
}

const char*	Form::GradeTooHighException::what () const throw ()
{
	return ("\e[1;3;31mForm::Exception: Grade is too high\e[0m");
}

const char*	Form::GradeTooLowException::what () const throw ()
{
	return ("\e[1;3;31mForm::Exception: Grade is too low\e[0m");
}
