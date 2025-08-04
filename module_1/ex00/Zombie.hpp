/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:09:55 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/04 12:27:52 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_H
# define	ZOMBIE_H

#include <iostream>

# define RED	"\e[2;3;31m"
# define WARN	"\e[2;3;91m"
# define GREEN	"\e[2;3;32m"
# define YELLOW	"\e[1;33m"
# define BLUE	"\e[1;34m"
# define MAGENT	"\e[1;35m"
# define CYAN	"\e[1;37m"
# define BG		"\e[1;107m"
# define RESET	"\e[0m"

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie () {};
		Zombie (std::string name);
		~Zombie ( void );
		void	announce( void );
};

#endif	//	ZOMBIE_H