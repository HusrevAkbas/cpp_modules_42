/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:06:45 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/11 15:57:15 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

# define RED	"\e[1;31m"
# define WARN	"\e[2;3;91m"
# define WARN2	"\e[2;3;92m"
# define WARN3	"\e[2;3;93m"
# define GREEN	"\e[1;32m"
# define YELLOW	"\e[1;33m"
# define BLUE	"\e[1;34m"
# define MAGENT	"\e[1;35m"
# define CYAN	"\e[1;37m"
# define BG		"\e[1;105m"
# define RESET	"\e[0m"

class	Animal
{
	protected:
		std::string	_type;
	public:
		Animal ();
		virtual ~Animal ();
		Animal( const std::string type );
		Animal( const Animal &other);
		Animal& operator=( const Animal &other);
		std::string	get_type( void );
		virtual void	make_sound( void );
};
