/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:24:02 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/20 22:52:54 by husrevakbas      ###   ########.fr       */
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
	
	{
		Array<int> tmp = arr;
		Array<int> tmp2(tmp);
		for (size_t i = 0; i < tmp2.size(); i++)
		{
			tmp2[i] = (int)(i * 5);
		}
		for (size_t i = 0; i < tmp2.size(); i++)
		{
		std::cout << tmp2[i] << " ";
		}
		std::cout << std::endl;
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

	return (0);
}
