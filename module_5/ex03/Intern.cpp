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

AForm*	Intern::makeForm(std::string formName, std::string target) const
{
	AForm	*form = NULL;
	int	id = -1;
	std::string	list[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (size_t i = 0; i < 3; i++)
	{
		if (formName == list[i])
			id = i;
	}
	switch (id)
	{
	case 0:
		form = new ShrubberyCreationForm(target);
		break;
	case 1:
		form = new RobotomyRequestForm(target);
		break;
	case 2:
		form = new PresidentialPardonForm(target);
		break;
	default:
		if (form)
			std::cout << "intern creates " << GREEN << form->getName() << RESET << std::endl;
		else
			std::cout << RED << "intern could'nt find " << formName << RESET << std::endl;
		break;
	}
	return (form);
}
