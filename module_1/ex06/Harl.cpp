/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:23:35 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/17 14:30:27 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << "\e[1;34mDebug message\e[0m" << std::endl;
}

void	Harl::info()
{
	std::cout << "\e[1;32mInfo message\e[0m" << std::endl;
}

void	Harl::warning()
{
	std::cout << "\e[1;33mWarning message\e[0m" << std::endl;
}

void	Harl::error()
{
	std::cout << "\e[1;31mError! message\e[0m" << std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*ptr_array[4])( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	array[4] = { "debug", "info", "warning", "error"};
	size_t		level_num;

	level_num = -1;
	for (size_t i = 0; i < 4; i++)
	{
		if (level == array[i])
			level_num = i;
	}
	switch (level_num)
	{
	case 0:
		std::cout << "[\e[1;34m DEBUG \e[0m]" << std::endl;
		(this->*ptr_array[0])();
	case 1:
		std::cout << "[\e[1;32m INFO \e[0m]" << std::endl;
		(this->*ptr_array[1])();
	case 2:
		std::cout << "[\e[1;33m WARNING \e[0m]" << std::endl;
		(this->*ptr_array[2])();
	case 3:
		std::cout << "[\e[1;31m ERROR \e[0m]" << std::endl;
		(this->*ptr_array[3])();
		break;
	default:
		std::cout << "[ This is not even a complain. Try better ]" << std::endl;
		break;
	}
}
