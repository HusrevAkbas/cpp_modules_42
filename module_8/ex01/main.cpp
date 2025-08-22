/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:40:33 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/22 16:55:54 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{	
	Span	span(10);
	span.addNumber(10);
	{
		Span	tmp(4);
		tmp.addNumber(12);
		std::cout << tmp.getNumber(0) << std::endl;
		tmp = span;
		Span	tmp2(span);
		std::cout << tmp.getNumber(0) << std::endl;
		std::cout << tmp2.getNumber(0) << std::endl;
	}
	try
	{
		span.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		span.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		for (size_t i = 1; i < span.size(); i++)
		{
			if (i % 2 == 0)
				span.addNumber((i + 5) * 3);
			else
				span.addNumber((i + 3) * 5);
		}
		for (size_t i = 0; i < span.size() ; i++)
		{
			std::cout << span.getNumber(i) << " ";
		}
		std::cout << std::endl << "shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "longest  span: " << span.longestSpan() << std::endl;
		for (size_t i = 0; i < 111; i++)
		{
			span.addNumber(i*10);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}
