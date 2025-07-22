/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:09:55 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/22 19:52:51 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_H
# define	ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie () {};
		Zombie (std::string name);
		~Zombie ( void );
		void	announce( void );
		void	setName( std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif	//	ZOMBIE_H