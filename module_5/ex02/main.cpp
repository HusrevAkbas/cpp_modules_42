/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:46:59 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/25 13:42:55 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	// AForm	form;
	srand(time(0));
	std::cout << BG_W << "-----------SHRUBBERY---------------------" << RESET << std::endl;
	try
	{
		AForm	*form = new ShrubberyCreationForm("A_42");
		Bureaucrat	adam = Bureaucrat("Adam", 146);
		std::cout << *form << std::endl;
		std::cout << adam << std::endl;
		adam.signForm(*form);
		adam.executeForm(*form);
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << "--------------------------------" << std::endl;
	try
	{
		AForm	*form = new ShrubberyCreationForm("B_42");
		Bureaucrat	adam = Bureaucrat("Adam", 145);
		std::cout << *form << std::endl;
		std::cout << adam << std::endl;
		adam.signForm(*form);
		adam.executeForm(*form);
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << "--------------------------------" << std::endl;
	try
	{
		AForm	*form = new ShrubberyCreationForm("C_42");
		Bureaucrat	adam = Bureaucrat("Adam", 137);
		std::cout << *form << std::endl;
		std::cout << adam << std::endl;
		adam.signForm(*form);
		adam.executeForm(*form);
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << std::endl << "-----------ROBOTOMY---------------------" << std::endl;
	try
	{
		AForm	*form = new RobotomyRequestForm("VICTIM_1");
		Bureaucrat	adam = Bureaucrat("Adam", 73);
		std::cout << *form << std::endl;
		std::cout << adam << std::endl;
		adam.signForm(*form);
		adam.executeForm(*form);
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << "--------------------------------" << std::endl;
	try
	{
		AForm	*form = new RobotomyRequestForm("VICTIM_2");
		Bureaucrat	adam = Bureaucrat("Adam", 72);
		std::cout << *form << std::endl;
		std::cout << adam << std::endl;
		adam.signForm(*form);
		adam.executeForm(*form);
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << "--------------------------------" << std::endl;
	try
	{
		AForm	*form = new RobotomyRequestForm("VICTIM_3");
		Bureaucrat	adam = Bureaucrat("Adam", 45);
		std::cout << *form << std::endl;
		std::cout << adam << std::endl;
		adam.signForm(*form);
		adam.executeForm(*form);
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << std::endl << "-----------PRESDENTIAL---------------------" << std::endl;
	try
	{
		AForm	*form = new PresidentialPardonForm("PARDON ME");
		Bureaucrat	adam = Bureaucrat("Adam", 26);
		std::cout << *form << std::endl;
		std::cout << adam << std::endl;
		adam.signForm(*form);
		adam.executeForm(*form);
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << "--------------------------------" << std::endl;
	try
	{
		AForm	*form = new PresidentialPardonForm("PARDON ME");
		Bureaucrat	adam = Bureaucrat("Adam", 25);
		std::cout << *form << std::endl;
		std::cout << adam << std::endl;
		adam.signForm(*form);
		adam.executeForm(*form);
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << "--------------------------------" << std::endl;
	try
	{
		AForm	*form = new PresidentialPardonForm("PARDON ME");
		Bureaucrat	adam = Bureaucrat("Adam", 5);
		std::cout << *form << std::endl;
		std::cout << adam << std::endl;
		adam.signForm(*form);
		adam.executeForm(*form);
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << "--------------------------------" << std::endl;

	return (0);
}
