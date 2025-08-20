/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:41 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/20 22:39:55 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class Array
{
	private:
		T	*_array;
		unsigned int	_size;
	public:
		Array<T>();
		~Array<T>();
		Array<T>(unsigned int n);
		Array<T>(const Array<T> &a);
		Array<T>& operator=(const Array<T> &a);
		T& operator[](int index);
		unsigned int	size() const;
		class IndexOutOfRangeException : public std::exception
		{
			public:
				const char *what() const throw ();
		};
};
