/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:23:35 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:05:55 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << BLUE 
	<< "I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-specialketchup burger."
	<< " I really do!" 
	<< RESET << std::endl;
}

void	Harl::info()
{
	std::cout << GREEN 
		<< "I cannot believe adding extra bacon costs more money."
		<< "You didn’t put enough bacon in my burger! "
		<< "If you did, I wouldn’t be asking for more!"
		<< RESET << std::endl;
}

void	Harl::warning()
{
	std::cout << YELLOW 
	<< "I think I deserve to have some extra bacon for free."
	<< " I’ve been coming for years, whereas you started "
	<< "working here just last month."
	<< RESET << std::endl;
}

void	Harl::error()
{
	std::cout << RED
	<< "This is unacceptable! I want to speak to the manager now."
	<< RESET << std::endl;
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
		std::cout << CYAN << "[ This is not even a complain. Try better ]" << RESET << std::endl;
		break;
	}
}
