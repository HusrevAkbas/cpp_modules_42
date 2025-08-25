/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 23:02:58 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/25 14:47:15 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data	d;

	d.name = "fortytwo";
	d.num = 42;
	std::cout << "pointer: " << &d << ", name: " << d.name << ", num: " << d.num << std::endl;
	
	uintptr_t	ptr = Serializer::serialize(&d);
	std::cout << "ptr: " << ptr << std::endl;
	Data	*d_ptr = Serializer::deserialize(ptr);
	std::cout << "pointer: " << d_ptr << ", name: " << d_ptr->name << ", num: " << d_ptr->num << std::endl;
	
}
