/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:28:17 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/27 19:16:05 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <filesystem>

int	main(int argc, char *argv[])
{
	size_t	start;
	size_t	end;
	std::string	ofilename;
	std::string	line;
	std::string	to_remove;
	std::string	to_put;
	std::string	content;
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
		std::cout << "Input file does not exist" << std::endl;
		return (0);
	}
	ofilename = argv[1];
	ofilename += ".replace";
	output_file.open(ofilename.c_str());
	if (!output_file)
	{
		std::cout << "Cannot open target file due to permissions" << std::endl;
		return (0);
	}
	to_remove = argv[2];
	to_put = argv[3];
	content = "";
	while (getline(input_file, line))
	{
		content += line;
		if (!input_file.eof())
			content += "\n";
	}
	end = 0;
	while (end < content.length() && content[end])
	{
		start = end;
		end = content.find(to_remove, start);
		if (end == std::string::npos)
			output_file << content.substr(start);
		else
		{
			output_file << content.substr(start, end - start);
			output_file << to_put;
			end += to_remove.length();
		}
	}
	return (0);
}
