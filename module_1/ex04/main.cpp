/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:28:17 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 13:39:44 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char *argv[])
{
	size_t	start;
	size_t	end;
	std::string	ofilename;
	std::string	line;
	std::string	remove;
	std::string	put;
	std::ifstream	input_file;
	std::ofstream	output_file;

	if (argc != 4)
	{
		std::cout << "\e[1;31;107mThis program takes always 3 arguments:\e[0m" << std::endl
		<< "filename   stringToRemove   stringToPut" << std::endl;
		return (0);
	}
	input_file.open(argv[1]);
	if (!input_file)
	{
		std::cout << "File does not exist" << std::endl;
		return (0);
	}
	ofilename = argv[1];
	ofilename += ".replace";
	output_file.open(ofilename);
	remove = argv[2];
	put = argv[3];
	while (getline(input_file, line))
	{
		end = 0;
		while (end < line.length() && line[end])
		{
			start = end;
			end = line.find(remove, start);
			if (end == std::string::npos)
				output_file << line.substr(start);
			else
			{
				output_file << line.substr(start, end - start);
				output_file << put;
				end += remove.length();
			}
		}
		output_file << std::endl;
	}
	return (0);
}
