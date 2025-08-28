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

		class iterator : public std::iterator<std::forward_iterator_tag, TYPE>
		{
			private:
				TYPE *data;
			public:
				iterator(TYPE *x) : data(x){}
				TYPE&	operator*() {	return (*data);	}
				iterator	&operator++() {	data += 1; return (*this);	}
				iterator	operator++(int) {	iterator tmp = *this; data += 1; return (tmp);	}
				bool	operator==(const iterator& other) const {	return (data == other.data);	}
				bool	operator!=(const iterator& other) const {	return (data != other.data);	}
		};
		iterator	begin();
		iterator	end();
};

#include "MutantStack.tpp"
