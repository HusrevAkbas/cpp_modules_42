/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:29:53 by huakbas           #+#    #+#             */
/*   Updated: 2025/07/13 17:50:43 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "iostream"

int	main()
{
	Contact cont;
	cont.set_first_name("ben");
	std::cout << cont.get_first_name() << std::endl;
	return (0);
}
