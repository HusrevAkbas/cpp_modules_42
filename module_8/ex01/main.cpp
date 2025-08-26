/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:40:33 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/26 13:26:30 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <list>

int	main()
{	
	Span	span(10);
	span.addNumber(10);
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
	
	std::cout << "------------------------------------------" << std::endl;
	Span	greater(11111);
	
	int	a = 123;
	int	arr[10] = { 12, 23, 33, 43, 54, 65, 76, 87, 98, 100 };
	greater.addNumbers(arr, 10);
	try
	{
		greater.addNumbers(11111, a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		for (size_t i = 0; i < greater.size(); i++)
		{
			std::cout << greater.getNumber(i) << " ";
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
