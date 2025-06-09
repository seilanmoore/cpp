/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:27:45 by smoore-a          #+#    #+#             */
/*   Updated: 2025/06/07 12:03:36 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits>
#include <exception>

Span::Span() : _numbers(), _size(0)
{
}

Span::Span(unsigned int n) : _numbers(), _size(static_cast<std::size_t>(n))
{
}

Span::Span(const Span &other) : _numbers(other._numbers),
								_size(other._size)
{
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	_numbers = other._numbers;
	_size = other._size;
	return *this;
}

Span::~Span()
{
}

void Span::addNumber()
{
	if (_size == 0)
		throw Span::EmptyException();
	if (_numbers.size() == _size)
		throw Span::FullException();
	std::vector<int> tmp(_size - _numbers.size());
	std::generate_n(tmp.begin(), tmp.size(), std::rand);
	_numbers.insert(_numbers.end(), tmp.begin(), tmp.end());
}

void Span::addNumber(long num)
{
	if (_size == 0)
		throw Span::EmptyException();
	if (_numbers.size() == _size)
		throw Span::FullException();
	if (num < std::numeric_limits<int>::min() ||
		num > std::numeric_limits<int>::max())
		throw Span::RangeException();
	else
		_numbers.push_back(num);
}

unsigned int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw Span::SpanException();
	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	unsigned int minDiff = std::numeric_limits<int>::min() + std::numeric_limits<int>::max();
	for (std::size_t i = 0; i < sorted.size() - 1; ++i)
	{
		unsigned int diff = static_cast<long>(sorted[i + 1]) - sorted[i];
		if (diff < minDiff)
			minDiff = diff;
	}
	return minDiff;
}

unsigned int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw Span::SpanException();
	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	unsigned int maxDiff = static_cast<long>(sorted.back()) - sorted.front();
	return maxDiff;
}

const std::vector<int> &Span::getNumbers() const
{
	return _numbers;
}

const char *Span::EmptyException::what() const throw()
{
	return "Size is zero, cannot store any number";
}

const char *Span::FullException::what() const throw()
{
	return "There is no room for more numbers";
}

const char *Span::SpanException::what() const throw()
{
	return "No elements or just one element, span cannot be found";
}

const char *Span::RangeException::what() const throw()
{
	return "Number cannot be stored becuase is out of bounds";
}

bool Span::_seed = (std::srand(static_cast<unsigned int>(std::time(NULL))), true);

static void printElement(int n)
{
	std::cout << n << '\n';
}

std::ostream &operator<<(std::ostream &os, const Span &numbers)
{
	if ((numbers.getNumbers()).empty())
		return os;
	std::vector<int>::const_iterator itBegin = (numbers.getNumbers()).begin();
	std::vector<int>::const_iterator itEnd = (numbers.getNumbers()).end();
	std::for_each(itBegin, itEnd, printElement);
	return os;
}
