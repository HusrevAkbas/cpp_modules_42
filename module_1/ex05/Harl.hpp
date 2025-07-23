/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:41:51 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 13:44:44 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HARL_H
# define HARL_H

# include <iostream>

# define RED	"\e[1;31m"
# define WARN	"\e[2;3;91m"
# define GREEN	"\e[1;32m"
# define YELLOW	"\e[1;33m"
# define BLUE	"\e[1;34m"
# define MAGENT	"\e[1;35m"
# define CYAN	"\e[1;37m"
# define BG		"\e[1;107m"
# define RESET	"\e[0m"

class Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
	public:
		Harl(){}
		~Harl(){}
		void	complain(std::string level);
};

#endif	//	HARL_H