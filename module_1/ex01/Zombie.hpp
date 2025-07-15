/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:09:55 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/15 23:07:19 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_H
# define	ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie () {};
		Zombie (std::string name);
		~Zombie ( void );
		void	announce( void );
		void	setName( std::string name);
};

#endif	//	ZOMBIE_H