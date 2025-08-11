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
