/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:14:46 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/20 11:48:36 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main()
{
	int	arr[5] = {1,2,3,4,5};

	iter(arr, 5, printT);
	std::cout << std::endl;

	iter(arr, 5, pow);

	iter(arr, 5, printT);
	std::cout << std::endl;

	iter(arr, 5, add42);

	iter(arr, 5, printT);
	std::cout << std::endl;

	std::string	s[4] = {"fortytwo", "thirty", "eleven", "nine"};

	iter(s, 4, printT);
	std::cout << std::endl;

	iter(s, 4, append42);

	iter(s, 4, printT);
	std::cout << std::endl;

	return (0);
}
