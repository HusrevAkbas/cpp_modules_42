/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:38:44 by huakbas           #+#    #+#             */
/*   Updated: 2025/09/11 15:35:12 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// inits containers with arguments for vector given in quotes: "3 2 1"
void	init_vector(std::vector<std::string> &arguments, std::vector<int> &vec)
{
	int					num;
	std::stringstream	sspart;

	for (std::vector<std::string>::iterator it = arguments.begin(); it != arguments.end(); it++)
	{
		sspart.clear();
		sspart.str(*it);
		sspart >> num;
		if (sspart.fail())
		{
			std::cerr << RED << "Error: invalid input: " << *it << "\n" << RESET;
			exit(2);
		}
		vec[it - arguments.begin()] = num;
	}
}

// inits containers with arguments for deque given in quotes: "3 2 1"
void	init_deque(std::vector<std::string> &arguments, std::deque<int> &deq)
{
	int					num;
	std::stringstream	sspart;

	for (std::vector<std::string>::iterator it = arguments.begin(); it != arguments.end(); it++)
	{
		sspart.clear();
		sspart.str(*it);
		sspart >> num;
		if (sspart.fail())
		{
			std::cerr << RED << "Error: invalid input: " << *it << "\n" << RESET;
			exit(2);
		}
		deq[it - arguments.begin()] = num;
	}
}

void	init_arguments(int argc, char **argv, std::vector<std::string> *arguments)
{
	if (argc < 2)
	{
		std::cerr << RED << "Error: need integer arguments. Example: \n" << RESET;
		std::cerr << RED << "./PmergeMe 3 2 1\n" << RESET;
		exit (1);
	}
	else if (argc > 2)
	{
		int	i = 1;
		while (argv[i])
		{
			arguments->push_back(argv[i]);
			i++;
		}
	}
	else
	{
		std::stringstream	ss(argv[1]);
		std::string			part;
		while (std::getline(ss, part, ' '))
			arguments->push_back(part);
	}
}
