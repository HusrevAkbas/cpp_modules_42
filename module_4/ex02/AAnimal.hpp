/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:06:45 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/09 16:10:23 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AANIMAL_H
# define	AANIMAL_H

# include <iostream>
# include "Brain.hpp"

class	AAnimal
{
	protected:
		std::string	_type;
	public:
		AAnimal ();
		virtual ~AAnimal();
		AAnimal (const std::string type);
		AAnimal (const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual void	make_sound( void ) = 0;
};

#endif	//	AANIMAL_H