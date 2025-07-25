/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Curel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:06:45 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 17:09:02 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CURE_H
# define	CURE_H

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class	Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure( std::string const & type );
		Cure( const Cure& other);
		Cure& operator=( const Cure& other);
		Cure*	clone( void ) const;
		void	use( ICharacter& target );
};

#endif	//	CURE_H