/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:09:55 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/04 12:41:50 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_H
# define	ZOMBIE_H

#include <iostream>

# define RED	"\e[2;3;31m"
# define GREEN	"\e[2;3;32m"
# define MAGENT	"\e[1;35m"
# define YELLOW	"\e[3;33m"
# define RESET	"\e[0m"

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie ();
		Zombie (std::string name);
		~Zombie ( void );
		void	announce( void );
		void	setName( std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif	//	ZOMBIE_H