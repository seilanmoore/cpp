/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:53:07 by smoore-a          #+#    #+#             */
/*   Updated: 2025/06/07 12:04:20 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <fstream>
#include <vector>
#include <exception>

class Span
{
public:
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber();
	void addNumber(long num);

	unsigned int shortestSpan();
	unsigned int longestSpan();

	const std::vector<int> &getNumbers() const;

	class EmptyException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class FullException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class SpanException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class RangeException : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	std::vector<int> _numbers;
	std::size_t _size;
	static bool _seed;
};

std::ostream &operator<<(std::ostream &os, const Span &numbers);

#endif
