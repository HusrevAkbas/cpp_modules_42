/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:24:02 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/28 14:05:43 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main()
{
	Array<int>	arr(10);
	
	for (size_t i = 0; i < arr.size(); i++)
	{
		arr[i] = (int)i;
	}
	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	Array<char>	arr2(26);
	for (size_t i = 0; i < arr2.size(); i++)
		arr2[i] = static_cast<char>(i + 65);
	{
		Array<char> tmp;
		tmp = arr2;
		std::cout << "tmp: ";
		for (size_t i = 0; i < tmp.size(); i++)
		{
			std::cout << tmp[i] << " ";
		}
		std::cout << "\n";
		Array<char> tmp2(tmp);
		std::cout << "tmp2: ";
		for (size_t i = 0; i < tmp2.size(); i++)
		{
			std::cout << tmp2[i] << " ";
		}
		std::cout << "\n";
	}
	
		std::cout << "arr2: ";
	for (size_t i = 0; i < arr2.size(); i++)
	{
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;

	try
	{
		arr2[27];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Array<std::string>	arr3(5);
	{
		Array<std::string> tmp (arr3);
	}
	for (size_t i = 0; i < arr3.size(); i++)
	{
		arr3[i] = "word_0";
		arr3[i][5] += i;
	}
	
	for (size_t i = 0; i < arr3.size(); i++)
	{
		std::cout << arr3[i] << " ";
	}
	std::cout << std::endl;

	try
	{
		arr3[-1];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
