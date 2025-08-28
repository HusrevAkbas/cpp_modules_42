/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:03:09 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/28 16:31:01 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "MutantStack.hpp"

int	main()
{
	MutantStack<float>	st;
	st.push(3e4f);
	st.push(3e4f);
	st.push(4e4f);
	st.push(2e4f);
	std::cout << st.top() << std::endl;
	st.push(5e4f);
	std::cout << st.top() << std::endl;

	MutantStack<float>::iterator it = st.begin();
	std::cout << "first item: " << *it << " " <<  "\n";

	std::replace(st.begin(), st.end(), 20000, 99999);
	for (MutantStack<float>::iterator i = st.begin(); i != st.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << "\n";

	float number = 22222;
	MutantStack<float>::iterator res = std::find(st.begin(), st.end(), number);
	if (res == st.end())
		std::cout << "Not found: " << number << "\n" ;
	else
		std::cout << "Found: " << *res << "\n";

	number = 99999;
	res = std::find(st.begin(), st.end(), number);
	if (res == st.end())
		std::cout << "Not found: " << number << "\n";
	else
		std::cout << "Found: " << *res << "\n";

	number = 30000;
	std::cout << "Number " << number << " found \e[1;32m"
	<< std::count(st.begin(), st.end(), number)
	<< "\e[0m times." << "\n";

	std::cout << "---------------------------------------" << std::endl;

	MutantStack<std::string>	strstc;
	strstc.push("Algea");
	strstc.push("Beatle");
	strstc.push("Cheetah");
	strstc.push("Donkey");
	strstc.push("Eagle");
	for (MutantStack<std::string>::iterator it = strstc.begin(); it != strstc.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
	
	std::string toFind = "99999";
	MutantStack<std::string>::iterator res2 = std::find(strstc.begin(), strstc.end(), toFind);
	if (res2 == strstc.end())
		std::cout << "Not found: " << toFind << "\n";
	else
		std::cout << "Found: " << *res2 << "\n";

	toFind = "Eagle";
	res2 = std::find(strstc.begin(), strstc.end(), toFind);
	if (res2 == strstc.end())
		std::cout << "Not found: " << toFind << "\n";
	else
		std::cout << "Found: " << *res2 << "\n";
	return (0);
}