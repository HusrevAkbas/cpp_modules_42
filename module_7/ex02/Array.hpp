/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:41 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/25 16:03:53 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class Array
{
	private:
		T		*_array;
		size_t	_size;
	public:
		Array<T>();
		~Array<T>();
		Array<T>(unsigned int n);
		Array<T>(const Array<T> &a);
		Array<T>& operator=(const Array<T> &a);
		T& operator[](size_t index);
		unsigned int	size() const;
		class IndexOutOfRangeException : public std::exception
		{
			public:
				const char *what() const throw ();
		};
};
