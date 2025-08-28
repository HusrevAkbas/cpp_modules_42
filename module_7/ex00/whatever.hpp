/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:55:12 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/28 13:31:29 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
void	swap(const T &a, const T &b)
{
	(void) a;
	(void) b;
	std::cout << "\e[1;31mCan't assign and swap const values!\e[0m" << std::endl;
}

template <typename T>
T	min(T &a, T &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T	max(T &a, T &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
