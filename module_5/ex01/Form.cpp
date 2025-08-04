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
{}

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

void	Form::beSigned(Bureaucrat &b)
{
	(void) b;
	this->_signed = 1;
	std::cout << b.getName() << " signed " << this->getName() << std::endl;
}

std::ostream& operator<< (std::ostream &o, Form &b)
{
	o << "Form: " << GREEN << b.getName()
	<< (b.isSigned() ? "\e[34m (signed)" : "\e[35m (not signed)") << RESET
	<< ", grade to sign: " << YELLOW << b.getGradeToSign() << RESET
	<< ", grade to execute: " << CYAN << b.getGradeToExecute() << RESET << std::endl;
	return (o);
}
