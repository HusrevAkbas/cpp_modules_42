/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:07:53 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/04 12:28:41 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main()
{
	Zombie	*zombie;
	Zombie	*zombie2;

	zombie = newZombie("dustin");
	zombie->announce();

	zombie2 = newZombie("clara");
	zombie2->announce();
	
	randomChump("randomGuy");
	
	randomChump("anotherRandomGuy");
	
	delete(zombie);
	delete(zombie2);
	return (0);
}
