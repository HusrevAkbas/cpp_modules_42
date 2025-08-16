/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:36 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:18:58 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern &a)
{	*this = a;	}

Intern& Intern::operator=(const Intern &a)
{
	(void) a;
	return (*this);
}

AForm	*Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	AForm	*form = NULL;
	AForm	*(Intern::*formList[3])(std::string) = 
	{
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};
	std::string	list[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	
	for (size_t i = 0; i < 3; i++)
	{
		if (formName == list[i])
		{
			form = (this->*formList[i])(target);
			break ;
		}
	}
	if (form)
		std::cout << "Intern creates " << GREEN << form->getName() << RESET << std::endl;
	else
		std::cout << RED << "Intern could'nt find " << formName << RESET << std::endl;
	return (form);
}
