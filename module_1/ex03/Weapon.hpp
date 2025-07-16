/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:06:42 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/16 15:12:56 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_H
# define	WEAPON_H

# include <iostream>

class Weapon
{
private:
	std::string	type;
public:
	// Weapon(){}
	~Weapon(){}
	Weapon(std::string type);
	const std::string	&getType( void );
	void				setType(std::string type);
};

#endif	//	WEAPON_H