/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:36 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:18:58 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename TYPE>
MutantStack<TYPE>::MutantStack(){}

template <typename TYPE>
MutantStack<TYPE>::~MutantStack(){}

template <typename TYPE>
MutantStack<TYPE>::MutantStack(const MutantStack<TYPE> &a)
{	*this = a;	}

template <typename TYPE>
MutantStack<TYPE>& MutantStack<TYPE>::operator=(const MutantStack<TYPE> &a)
{
	(void) a;
	// assign variables here
	return (*this);
}

template <typename TYPE>
typename MutantStack<TYPE>::iterator MutantStack<TYPE>::begin()
{
	TYPE *ptr = &(this->top());
	ptr -= this->size() - 1;
	return (MutantStack<TYPE>::iterator(ptr));
}

template <typename TYPE>
typename MutantStack<TYPE>::iterator MutantStack<TYPE>::end()
{
	TYPE *ptr	= &(this->top());
	ptr++;
	return (MutantStack<TYPE>::iterator(ptr));
}

template <typename TYPE>
TYPE& MutantStack<TYPE>::operator[](size_t index)
{
	if (index >= this->size())
		throw MutantStack<TYPE>::IndexIsOutOfRangeException();
	return (*(this->begin() + index));
}
