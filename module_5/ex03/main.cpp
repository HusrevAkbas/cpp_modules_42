/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:46:59 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/26 17:12:07 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AForm.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	srand(time(0));
	std::cout << BG_W << "--------------------------------" << RESET << std::endl;
	try
	{
		Intern	intern;
		AForm	*form = intern.makeForm("shrubbery creation", "A_42");
		Bureaucrat	adam = Bureaucrat("Adam", 16);
		std::cout << adam << std::endl;
		if (form)
		{
			std::cout << *form << std::endl;
			adam.signForm(*form);
			adam.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("robotomy request", "B_42");
		if (form)
		{
			std::cout << *form << std::endl;
			adam.signForm(*form);
			adam.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("presidential pardon", "CILLYWOOD");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}

	return (0);
}
