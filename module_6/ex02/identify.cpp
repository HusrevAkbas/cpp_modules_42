/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 23:37:07 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/20 00:20:37 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cstdlib>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int	random;

	random = rand();
	if (random % 3 == 0)
	{
		std::cout << "A generated" << std::endl;
		return (new A());
	}
	if (random % 3 == 1)
	{
		std::cout << "B generated" << std::endl;
		return (new B());
	}
	std::cout << "C generated" << std::endl;
	return (new C());
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "pointed class is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "pointed class is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "pointed class is C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "referenced class is A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "referenced class is B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "referenced class is C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	
}

int	main(int argc, char **argv)
{
	size_t	loop = 1;
	std::istringstream	ss;
	std::string	input;

	if (argc == 2)
	{
		input = argv[1];
		ss.str(input);
		ss >> loop;
		if (ss.fail())
			loop = 1;
	}
	for (size_t i = 0; i < loop; i++)
	{
		Base	*cl = generate();
		
		identify(*cl);
		identify(cl);
		delete(cl);
		std::cout << "--------------------------------------------" << std::endl;
	}
	return (0);
}