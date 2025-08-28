/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:41 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/28 14:02:50 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define	YELLOW	"\e[3;33m"
# define	RESET	"\e[0m"

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

#include	"Array.tpp"
