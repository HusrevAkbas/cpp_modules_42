/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:46:59 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/14 16:18:30 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
	try
	{
		AForm	*form = new ShrubberyCreationForm("TARGET");
		Bureaucrat	adam = Bureaucrat("Adam", 137);
		Bureaucrat	berry = Bureaucrat("Berry", 42);
		std::cout << *form << std::endl;
		std::cout << adam << std::endl;
		adam.signForm(*form);
		berry.signForm(*form);
		form->execute(adam);
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << "--------------------------------" << std::endl;
	try
	{
		AForm	*form = new RobotomyRequestForm("ROBOTIZE ME");
		Bureaucrat	adam = Bureaucrat("Adam", 12);
		Bureaucrat	berry = Bureaucrat("Berry", 70);
		std::cout << *form << std::endl;
		std::cout << adam << std::endl;
		adam.signForm(*form);
		berry.signForm(*form);
		form->execute(adam);
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << "--------------------------------" << std::endl;

	return (0);
}
