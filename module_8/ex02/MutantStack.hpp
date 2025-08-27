/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:41 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:11:15 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <algorithm>

template <typename TYPE>
class MutantStack	:	public std::stack< TYPE, std::vector<TYPE> >
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &a);
		MutantStack& operator=(const MutantStack &a);

		class iterator	:	public std::iterator
		<
			std::forward_iterator_tag,
			TYPE,
			TYPE,
			const TYPE*,
			TYPE
		>	{
			private:
				TYPE	*start;
			public:
				iterator(TYPE& top, size_t size)	//default constructor
				{
					std::cout << top << " | " << size << std::endl;
					start = &top - (size - 1) * sizeof(TYPE);
				}
				iterator&	operator++();		// pre increment
				iterator	operator++(int);	// post increment
				bool		operator== (iterator other) const;
				bool		operator!= (iterator other) const;
				TYPE&		operator* () const;
		};
		iterator	begin();
		iterator	end();
};
