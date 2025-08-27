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
	return (MutantStack<TYPE>::iterator(this->top(), this->size()));
}

template <typename TYPE>
typename MutantStack<TYPE>::iterator MutantStack<TYPE>::end()
{
	return (MutantStack<TYPE>::iterator(this->top(), -1));
}

// TODO: work on this one
template <typename TYPE>
TYPE& MutantStack<TYPE>::iterator::operator*() const
{
	return ((TYPE&) *this);
}
