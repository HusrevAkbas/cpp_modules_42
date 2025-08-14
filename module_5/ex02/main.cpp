/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:46:59 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/14 14:36:21 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	try
	{
		AForm	*form = new ShrubberyCreationForm("TARGET");
		Bureaucrat	adam = Bureaucrat("Adam", 145);
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

	return (0);
}
