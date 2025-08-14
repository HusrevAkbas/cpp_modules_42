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
	AForm("ShrubberyCreationForm", 145, 137, "DEFAULT TARGET")
{}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target) :
	AForm("ShrubberyCreationForm", 145, 137, target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &a) :
	AForm(a.AForm::getName(), a.AForm::getGradeToExecute(), a.AForm::getGradeToSign(), a.AForm::getTarget())
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

void	ShrubberyCreationForm::execute(const Bureaucrat  & executor) const
{
	std::ofstream	oFile(this->getTarget().c_str(), std::ofstream::app);
	try
	{
		if ((*this).AForm::mayExecute(executor))
		{
			// oFile.open(this->getTarget().c_str());
			if (!oFile)
			{
				std::cerr << "Error on creating file" << std::endl;
				std::cout << GREEN << this->getName() << RESET
				<< " not executed because " << MAGENT << this->getTarget() << RESET << " is invalid" << std::endl;
				return ;
			}
			oFile << "Shrubbery planted here and there" << std::endl;
			std::cout << GREEN << this->getName() << RESET
			<< " executed and your shrubberies are planted to "
			<< MAGENT <<  this->getTarget() << RESET << std::endl;
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