/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacterl.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:06:45 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 17:09:02 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define RED	"\e[1;31m"
# define WARN	"\e[2;3;95m"
# define WARN2	"\e[2;3;91m"
# define WARN3	"\e[2;3;93m"
# define WARN4	"\e[2;3;94m"
# define GREEN	"\e[1;32m"
# define YELLOW	"\e[1;33m"
# define BLUE	"\e[1;34m"
# define MAGENT	"\e[1;35m"
# define CYAN	"\e[1;96m"
# define GRAY	"\e[1;90m"
# define BG		"\e[1;105m"
# define RESET	"\e[0m"

class AMateria;

class	ICharacter
{
	public:
		virtual	~ICharacter() {}
		virtual	std::string const & getName() const = 0;
		virtual	void	equip( AMateria *m ) = 0;
		virtual	void	unequip( int idx ) = 0;
		virtual	void	use( int idx, ICharacter &target) = 0;
};
