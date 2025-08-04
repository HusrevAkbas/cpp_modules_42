/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:10:13 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/04 12:47:52 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMANB_H
# define	HUMANB_H

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon		*_weapon;
	public:
		//	HumanB () {}
		~HumanB ();
		HumanB(std::string name);
		void	setWeapon(Weapon &weapon);
		void	attack();
};

#endif	//	HUMANB_H
