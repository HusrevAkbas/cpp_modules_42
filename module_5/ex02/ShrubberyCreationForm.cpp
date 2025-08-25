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

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", false, 145, 137, "DEFAULT TARGET")
{}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target) :
	AForm("ShrubberyCreationForm", false, 145, 137, target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &a) :
	AForm(a.AForm::getName(), a.isSigned(), a.AForm::getGradeToExecute(), a.AForm::getGradeToSign(), a.AForm::getTarget())
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a)
{
	(void) a;
	return (*this);
}

std::ostream& operator<< (std::ostream &o, ShrubberyCreationForm &b)
{
	o << "Form: " << GREEN << b.getName()
	<< (b.isSigned() ? "\e[34m (signed)" : "\e[35m (not signed)") << RESET
	<< ", grade to sign: " << YELLOW << b.getGradeToSign() << RESET
	<< ", grade to execute: " << CYAN << b.getGradeToExecute() << RESET;
	return (o);
}

void	ShrubberyCreationForm::doTheJob(void) const
{
	std::string	filename = this->getTarget() + "_shrubbery";
	std::ofstream	oFile(filename.c_str(), std::ofstream::app);
	if (!oFile)
	{
		std::cerr << "Error on creating file" << std::endl;
		std::cout << GREEN << this->getName() << RESET
		<< " not executed because " << MAGENT << this->getTarget() << RESET << " is invalid" << std::endl;
		return ;
	}
	oFile << SHRUBBERY << std::endl;
	std::cout << GREEN << this->getName() << RESET
	<< " executed and your shrubberies are planted to "
	<< MAGENT <<  this->getTarget() << RESET << std::endl;
}
