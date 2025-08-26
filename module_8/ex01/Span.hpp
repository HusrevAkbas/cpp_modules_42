/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:41 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:11:15 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <limits>

class Span
{
	private:
		int	*_numbers;
		size_t	_size;
		size_t	_index;

	public:
		Span();
		~Span();
		Span(unsigned int N);
		Span(const Span &a);
		Span& operator=(const Span &a);
		size_t	size() const;
		void	addNumber(int num);
		void	addNumbers(size_t count, int num);
		void	addNumbers(int *num_array, size_t size);
		int		getNumber(unsigned int num) const;
		int		shortestSpan();
		int		longestSpan();
		class IndexIsOutOfRangeException : public std::exception
		{
			public:
				const char	*what() const throw ();
		};
		class NotEnoughElementsException : public std::exception
		{
			public:
				const char	*what() const throw ();
		};
};