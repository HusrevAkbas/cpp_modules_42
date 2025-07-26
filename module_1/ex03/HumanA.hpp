/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:11:23 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/26 14:15:49 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMANA_H
# define	HUMANA_H

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon&		_weapon;
	public:
		// HumanA(){}
		~HumanA(){}
		HumanA(std::string name, Weapon& weapon);
		void	attack();
};

#endif	//	HUMANA_H
