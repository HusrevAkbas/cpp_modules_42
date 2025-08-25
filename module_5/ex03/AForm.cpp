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

#include "AForm.hpp"

AForm::AForm() :
	_name("Default"),
	_signed(false),
	_grade_to_sign(22),
	_grade_to_execute(11),
	_target("DEFAULT TARGET")
{}

AForm::AForm( std::string name, bool sign, int grade_to_sign, int grade_to_execute, std::string target ) :
	_name(name),
	_signed(sign),
	_grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute),
	_target(target)
{
	if (_grade_to_execute < 1 || _grade_to_sign < 1)
		throw AForm::GradeTooHighException();
	if (_grade_to_execute > 150 || _grade_to_sign > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm(){}

AForm::AForm(const AForm &a) :
	_name(a._name),
	_signed(a._signed),
	_grade_to_sign(a._grade_to_sign),
	_grade_to_execute(a._grade_to_execute),
	_target(a._target)
{}

AForm& AForm::operator=(const AForm &a)
{
	this->_signed = a._signed;
	return (*this);
}

const std::string	AForm::getName() const
{	return (this->_name);	}

const std::string	AForm::getTarget() const
{	return (this->_target);	}

int	AForm::getGradeToExecute() const
{	return (this->_grade_to_execute);	}

int	AForm::getGradeToSign() const
{	return (this->_grade_to_sign);	}

bool	AForm::isSigned() const
{	return (this->_signed);	}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeToSign())
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execute(const Bureaucrat &b) const
{
	if (!this->isSigned())
		throw AForm::FormIsNotSignedException();
	if (b.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	this->doTheJob();
}

std::ostream& operator<< (std::ostream &o, AForm &b)
{
	o << "Form: " << GREEN << b.getName()
	<< (b.isSigned() ? "\e[34m (signed)" : "\e[35m (not signed)") << RESET
	<< ", grade to sign: " << YELLOW << b.getGradeToSign() << RESET
	<< ", grade to execute: " << CYAN << b.getGradeToExecute() << RESET;
	return (o);
}

const char*	AForm::GradeTooHighException::what () const throw ()
{
	return ("\e[1;3;31mForm::Exception: Grade is too high\e[0m");
}

const char*	AForm::GradeTooLowException::what () const throw ()
{
	return ("\e[1;3;31mForm::Exception: Grade is too low\e[0m");
}

const char*	AForm::FormIsNotSignedException::what () const throw ()
{
	return ("\e[1;3;31mForm::Exception: Form is not signed\e[0m");
}