/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:25:53 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/23 18:20:04 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLAPTRAP_H
# define	CLAPTRAP_H

# include <iostream>

# define RED	"\e[1;31m"
# define WARN	"\e[2;3;91m"
# define WARN2	"\e[2;3;92m"
# define GREEN	"\e[1;32m"
# define YELLOW	"\e[1;33m"
# define BLUE	"\e[1;34m"
# define MAGENT	"\e[1;35m"
# define CYAN	"\e[1;37m"
# define BG		"\e[1;105m"
# define RESET	"\e[0m"

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attak_damage;
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap &operator=( const ClapTrap &other);
		void	attack( const std::string& target );
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif //CLAPTRAP_H