/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:07:53 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/22 19:37:36 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main()
{
	Zombie	*zombie;

	zombie = newZombie("dustin");
	zombie->announce();
	delete(zombie);

	zombie = newZombie("clara");
	zombie->announce();
	delete(zombie);

	randomChump("randomGuy");

	randomChump("anotherRandomGuy");

	return (0);
}
