/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:45:57 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/21 15:01:40 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

#include <list>

#include <set>

#include <map>	// associative container

#include <stack>	// doesn't have default iterator

#include <queue>	// doesn't have default iterator

#include <iostream>

#include "easyfind.hpp"

int	main()
{
	std::vector<int>	vec;

	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(1);
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec.at(i) << " ";
	std::cout << std::endl;
	try
	{
		std::cout << easyfind(vec, 3) << std::endl;
		std::cout << easyfind(vec, 5) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::list<int>	ls;
	ls.push_back(1);
	ls.push_back(11);

	try
	{
		std::cout << easyfind(ls, 11) << std::endl;
		std::cout << easyfind(ls, 1) << std::endl;
		std::cout << easyfind(ls, 5) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::set<int>	st;
	st.insert(2);
	st.insert(22);

	try
	{
		std::cout << easyfind(st, 22) << std::endl;
		std::cout << easyfind(st, 2) << std::endl;
		std::cout << easyfind(st, 5) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
