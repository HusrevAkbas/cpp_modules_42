/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:41 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:11:15 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm	*makeShrubberyCreationForm(std::string target);
		AForm	*makeRobotomyRequestForm(std::string target);
		AForm	*makePresidentialPardonForm(std::string target);
	public:
		Intern();
		~Intern();
		Intern(const Intern &a);
		Intern& operator=(const Intern &a);
		AForm	*makeForm(std::string formName, std::string target);
};
