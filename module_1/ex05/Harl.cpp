/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:23:35 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/17 14:01:53 by husrevakbas      ###   ########.fr       */
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
	void		(Harl::*ptr)( void );
	void		(Harl::*ptr_array[4])( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	array[4] = { "debug", "info", "warning", "error"};

	ptr = nullptr;
	for (size_t i = 0; i < 4; i++)
	{
		if (level == array[i])
			ptr = ptr_array[i];
	}
	if (ptr)
	{
		(this->*ptr)();
		return ;
	}
	std::cout << "That's great. No one is complaining!" << std::endl;
}
