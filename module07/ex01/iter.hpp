/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:49:25 by smoore-a          #+#    #+#             */
/*   Updated: 2025/06/02 10:12:23 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cctype>

template <typename T>
void printElement(const T &element)
{
	std::cout << element << " ";
}

void printInteger(int n)
{
	std::cout << n << " ";
}

template <typename T>
void incrementElement(T &element)
{
	++element;
}

void toUpper(std::string &s)
{
	for (std::size_t i = 0; i < s.length(); ++i)
	{
		s[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[i])));
	}
}

template <typename T, typename Func>
void iter(T *array, std::size_t length, Func function)
{
	if (!array)
		return;
	for (std::size_t i = 0; i < length; ++i)
		function(array[i]);
}

#endif
