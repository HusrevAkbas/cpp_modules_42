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

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5, "DEFAULT TARGET")
{}

PresidentialPardonForm::PresidentialPardonForm( std::string target) :
	AForm("PresidentialPardonForm", 25, 5, target)
{}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &a) :
	AForm(a.AForm::getName(), a.AForm::getGradeToExecute(), a.AForm::getGradeToSign(), a.AForm::getTarget())
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &a)
{
	(void) a;
	return (*this);
}

std::ostream& operator<< (std::ostream &o, PresidentialPardonForm &b)
{
	o << "Form: " << GREEN << b.getName()
	<< (b.isSigned() ? "\e[34m (signed)" : "\e[35m (not signed)") << RESET
	<< ", grade to sign: " << YELLOW << b.getGradeToSign() << RESET
	<< ", grade to execute: " << CYAN << b.getGradeToExecute() << RESET;
	return (o);
}

void	PresidentialPardonForm::execute(const Bureaucrat  & executor) const
{
	try
	{
		if ((*this).AForm::mayExecute(executor))
		{
			std::cout << MAGENT << this->getTarget() << RESET
			<< " has been pardoned by Zaphod Beeblebrox" << std::endl;
		}
		else
			std::cout << GREEN << this->getName() << RESET
			<< " not executed because it is not signed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << GREEN << this->getName() << RESET
		<< " not executed because " << e.what() << std::endl;
	}
}
