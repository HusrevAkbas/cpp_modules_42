/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:07:53 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/15 22:27:58 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main()
{
	Zombie	*zombie;

	zombie = newZombie("dustin");
	zombie->announce();
	randomChump("randomGuy");
	return (0);
}
