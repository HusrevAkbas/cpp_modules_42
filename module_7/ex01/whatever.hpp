/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:15:13 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/20 11:46:22 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void	iter(T arr[], size_t size, void func(T&))
{
	for (size_t i = 0; i < size; i++)
		func(arr[i]);
}

template <typename T>
void	printT(T const item)
{
	std::cout << item << " ";
}

template <typename T>
void	append42(T &item)
{
	item += "42";
}

template <typename T>
void	add42(T &item)
{
	item += 42;
}

template <typename T>
void	pow(T &num)
{
	num *= num;
}