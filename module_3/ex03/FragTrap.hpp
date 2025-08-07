/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:15:27 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/07 20:58:18 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRAGTRAP_H
# define	FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
	public:
		FragTrap();
		~FragTrap();
		FragTrap( const std::string name );
		FragTrap( const FragTrap &other);
		FragTrap& operator=( const FragTrap &other);
		void	highFivesGuys( void );
};

#endif	//	FRAGTRAP_H