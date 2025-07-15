/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:23:31 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/15 22:24:52 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MAIN_H
# define MAIN_H

# include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump( std::string name );

#endif