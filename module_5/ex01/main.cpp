/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:46:59 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/04 17:58:24 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main()
{
	Form	form("Simpleform", 33, 44);
	Bureaucrat	bob("bob", 12);

	std::cout << form << std::endl;
	form.beSigned(bob);
	std::cout << form << std::endl;

	return (0);
}
