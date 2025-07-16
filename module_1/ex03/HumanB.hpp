/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:10:13 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/16 15:17:10 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMANB_H
# define	HUMANB_H

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		//	HumanB () {}
		~HumanB () {}
		HumanB(std::string name);
		void	setWeapon(Weapon &weapon);
		void	attack();
};

#endif	//	HUMANB_H
