/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:46:59 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/13 18:19:47 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main()
{
	try
	{
		AForm	form("A form", 44, 22);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << "--------------------------------" << std::endl;
	try
	{
		AForm	form("B form", 151, 22);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << "--------------------------------" << std::endl;
	try
	{
		AForm	form("C form", 24, 151);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << "--------------------------------" << std::endl;
	try
	{
		AForm	form("CA form", 0, 22);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << "--------------------------------" << std::endl;
	try
	{
		AForm	form("CB form", 24, 0);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << "--------------------------------" << std::endl;
	try
	{
		Bureaucrat	b("Bob", 99);
		AForm	form("D form", 124, 22);
		std::cout << form << std::endl;
		std::cout << b << std::endl;
		b.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	std::cout << "--------------------------------" << std::endl;
	try
	{
		Bureaucrat	b("Bob", 99);
		AForm	form("E form", 14, 22);
		std::cout << form << std::endl;
		std::cout << b << std::endl;
		b.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';	}
	

	return (0);
}
