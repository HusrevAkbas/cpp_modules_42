/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:24:02 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/25 16:10:21 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"

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
	{
		Array<char> tmp = arr2;
	}
	for (size_t i = 0; i < arr2.size(); i++)
		arr2[i] = static_cast<char>(i + 65);
	
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
