/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:11:23 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:12:28 by huakbas          ###   ########.fr       */
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