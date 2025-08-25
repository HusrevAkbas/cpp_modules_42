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

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", false, 72, 45, "DEFAULT TARGET")
{}

RobotomyRequestForm::RobotomyRequestForm( std::string target) :
	AForm("RobotomyRequestForm", false, 72, 45, target)
{}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &a) :
	AForm(a.AForm::getName(), a.isSigned(), a.AForm::getGradeToExecute(), a.AForm::getGradeToSign(), a.AForm::getTarget())
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &a)
{
	(void) a;
	return (*this);
}

std::ostream& operator<< (std::ostream &o, RobotomyRequestForm &b)
{
	o << "Form: " << GREEN << b.getName()
	<< (b.isSigned() ? "\e[34m (signed)" : "\e[35m (not signed)") << RESET
	<< ", grade to sign: " << YELLOW << b.getGradeToSign() << RESET
	<< ", grade to execute: " << CYAN << b.getGradeToExecute() << RESET;
	return (o);
}

void	RobotomyRequestForm::doTheJob(void) const
{
	std::cout << " ** make some noise ** " << std::endl;
	if (rand() % 2 == 0)
		std::cout << MAGENT << this->getTarget() << RESET << " is robotomized! " << std::endl;
	else
		std::cout << RED << "Robotomy failed for " << MAGENT << this->getTarget() << RESET << std::endl;
}
