/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:19:21 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/07 11:55:50 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	don("Don");

	don.attack("Ron");
	don.whoAmI();
	don.beRepaired(10);

	return (0);
}