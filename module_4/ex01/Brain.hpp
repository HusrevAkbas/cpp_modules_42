/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:06:45 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 15:12:26 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define RED	"\e[1;31m"
#define WARN	"\e[2;3;91m"
#define WARN2	"\e[2;3;92m"
#define WARN3	"\e[2;3;93m"
#define WARN4	"\e[2;3;94m"
#define GREEN	"\e[1;32m"
#define YELLOW	"\e[1;33m"
#define BLUE	"\e[1;34m"
#define MAGENT	"\e[1;35m"
#define CYAN	"\e[1;36m"
#define GRAY	"\e[1;90m"
#define BG		"\e[1;105m"
#define RESET	"\e[0m"

class	Brain
{
	protected:
		std::string	_ideas[100];
	public:
		Brain ();
		~Brain ();
		Brain( const std::string type[100] );
		Brain( const Brain &other);
		Brain& operator=( const Brain &other);
		std::string*	get_ideas ( void );
		void	make_sound( void );
		std::string	getIdea(int index);
		void	setIdea(int index, std::string idea);
};
