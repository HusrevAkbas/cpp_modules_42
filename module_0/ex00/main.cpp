/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:42:33 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/13 16:00:10 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

int	main(int argc, char **argv)
{
	int			word_i;
	std::string	word;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	word_i = 1;
	while (argv[word_i])
	{
		word = argv[word_i];
		for (int i = 0; i < (int)word.length(); i++)
			word[i] = std::toupper(word[i]);
		std::cout << word;
		word_i++;
	}
	std::cout << std::endl;
	return (0);
}
