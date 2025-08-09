/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:06:45 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/24 15:12:26 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CAT_H
# define	CAT_H

# include <iostream>
# include "AAnimal.hpp"

class	Cat : public AAnimal
{
	private:
		Brain	*_brain;
	protected:
		std::string	_type;
	public:
		Cat ();
		~Cat ();
		Cat( const Cat &other);
		Cat& operator=( const Cat &other);
		std::string	get_type();
		void	make_sound( void );
		std::string	getIdea(int index);
		void	setIdea(int index, std::string idea);
};

#endif	//	CAT_H