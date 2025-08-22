/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:45:57 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/22 17:21:02 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Stores elements like an array but can dynamically change in size.
	Adding and removing of elements are usually done at the end.
	Elements can be accessed by index.
*/
#include <vector>
/*
	Stores elements sequentially, where each element is connected to the next.
	Adding and removing of elements can be done at both ends.
	Not accessible by index.
*/
#include <list>
/*
	Stores unique elements. Not accessible by index.
*/
#include <set>
/*
	Stores elements in "key/value" pairs. Accessible by keys (not by index).
*/
#include <map>	// associative container
/*
	Stores elements in a specific order, called LIFO (Last In, First Out),
	where elements can only be added and removed from the top.
	Not accessible by index.
*/
#include <stack>	// doesn't have iterator
/*
	Stores elements in a specific order, called FIFO (First In, First Out),
	where elements are added at the end and removed from the front.
	Not accessible by index.
*/
#include <queue>	// doesn't have iterator
/*
	Stores elements in a double-ended queue, where elements can be added
	and removed from both ends.
	Elements can be accessed by index.
*/
#include <deque>

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

	std::deque<int>	dq;
	dq.push_back(3);
	dq.push_back(33);

	try
	{
		std::cout << easyfind(dq, 33) << std::endl;
		std::cout << easyfind(dq, 3) << std::endl;
		std::cout << easyfind(dq, 5) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
