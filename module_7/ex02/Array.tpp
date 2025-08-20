/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:36 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/08/20 22:41:53 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0)
{
	std::cout << "default const " << this->_size << std::endl;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	std::cout << "parameter const " << this->_size << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T> &a) : _array(new T[0])
{
	if (this != &a)
		*this = a;
	std::cout << "copy const " << this->_size << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &a)
{
	delete[] this->_array;
	this->_array = new T[a._size];
	for (size_t i = 0; i < a._size; i++)
		this->_array[i] = a._array[i];
	this->_size = a._size;
	return (*this);
}

template <typename T>
unsigned int Array<T>::size() const
{	return (this->_size);	}

template <typename T>
const char* Array<T>::IndexOutOfRangeException::what(void) const throw()
{
	return ("\e[1;3;31mIndex is out of range!\e[0m");
}

template <typename T>
T& Array<T>::operator[](int index)
{
	if (index < 0 || index >= static_cast<int>(this->_size))
		throw Array<T>::IndexOutOfRangeException();
	return (this->_array[index]);
}