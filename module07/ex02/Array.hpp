/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:56:33 by smoore-a          #+#    #+#             */
/*   Updated: 2025/06/02 10:03:31 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();

	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;

	unsigned int size() const;

private:
	T *_content;
	unsigned int _size;
};

template <typename T>
Array<T>::Array() : _content(0), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _content(0), _size(n)
{
	if (!n)
		return;
	_content = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &other) : _content(0), _size(0)
{
	if (other._size > 0)
	{
		T *tmpContent = new T[other._size];
		try
		{
			for (unsigned int i = 0; i < other._size; ++i)
			tmpContent[i] = other._content[i];
		}
		catch (const std::exception &e)
		{
			delete[] tmpContent;
			std::cerr << "Exception: " << e.what() << std::endl;
			throw;
		}
		_content = tmpContent;
		_size = other._size;
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return *this;
	T *newContent = 0;
	unsigned int newSize = other._size;
	if (newSize > 0)
	{
		newContent = new T[newSize];
		try
		{
			for (unsigned int i = 0; i < newSize; ++i)
				newContent[i] = other._content[i];
		}
		catch (const std::exception &e)
		{
			delete[] newContent;
			std::cerr << "Exception: " << e.what() << std::endl;
			throw;
		}
	}
	delete[] _content;
	_content = newContent;
	_size = newSize;
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _content;
	_content = NULL;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
	{
		std::cerr << "Exception: index is out of bounds" << std::endl;
		throw std::exception();
	}
	return _content[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
	{
		std::cerr << "Exception: index is out of bounds" << std::endl;
		throw std::exception();
	}
	return _content[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif
