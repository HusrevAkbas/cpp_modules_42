/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:36 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:18:58 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iterator>

Span::Span() : _numbers(new int[0]), _size(0), _index(0)
{}

Span::~Span()
{
	delete [] this->_numbers;
}

Span::Span(unsigned int N) : _numbers(new int[N]), _size(N), _index(0)
{}

Span::Span(const Span &a) : _numbers(new int[0]), _size(a._size), _index(a._index)
{
	if (this == &a)
		return ;
	*this = a;
}

Span& Span::operator=(const Span &a)
{
	if (this == &a)
		return (*this);
	delete[] this->_numbers;
	this->_numbers = new int[a._size];
	for (size_t i = 0; i < a._index; i++)
		this->_numbers[i] = a._numbers[i];
	this->_size = a._size;
	this->_index = a._index;
	return (*this);
}

size_t	Span::size() const
{	return (this->_size);	}

void	Span::addNumber(int num)
{
	if (this->_index >= this->_size)
		throw Span::IndexIsOutOfRangeException();
	this->_numbers[this->_index] = num;
	this->_index++;
}

void	Span::addNumbers(size_t count, int num)
{
	for (size_t i = 0; i < count; i++)
	{
		if (this->_index >= this->_size)
			throw Span::IndexIsOutOfRangeException();
		this->_numbers[_index] = num;
		this->_index++;
	}
}

void	Span::addNumbers(int *arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (this->_index >= this->_size)
			throw Span::IndexIsOutOfRangeException();
		this->_numbers[_index] = arr[i];
		this->_index++;
	}
}

int	Span::getNumber(unsigned int index) const
{
	if (index >= this->_index)
		throw Span::IndexIsOutOfRangeException();
	return (this->_numbers[index]);
}

int	Span::shortestSpan()
{
	if (this->_index < 2)
		throw Span::NotEnoughElementsException();

	std::sort(this->_numbers, this->_numbers + this->_index);

	int	span = std::numeric_limits<int>::max();

	for (size_t i = 0; i < this->_index - 1; i++)
	{
		if (span > this->_numbers[i + 1] - this->_numbers[i])
			span = this->_numbers[i + 1] - this->_numbers[i];
	}
	return (span);
}

int	Span::longestSpan()
{
	if (this->_index < 2)
		throw Span::NotEnoughElementsException();
	std::sort(this->_numbers, this->_numbers + this->_index);

	return (this->_numbers[this->_index - 1] - this->_numbers[0]);
}

const char* Span::IndexIsOutOfRangeException::what() const throw ()
{
	return ("\e[1;31mIndex is out of range\e[0m");
}

const char* Span::NotEnoughElementsException::what() const throw ()
{
	return ("\e[1;31mNot enough elements to calculate span\e[0m");
}
