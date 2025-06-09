/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 11:49:15 by smoore-a          #+#    #+#             */
/*   Updated: 2025/06/07 19:47:24 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>
#include <fstream>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack() {};
	MutantStack(const MutantStack &other) : std::stack<T>(other) {};
	MutantStack &operator=(const MutantStack &other)
	{
		if (this == &other)
			return *this;
		std::stack<T>::operator=(other);
		return *this;
	};
	~MutantStack() {};

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const MutantStack<T> &ms)
{
	if (ms.empty())
		return os;
	typedef typename MutantStack<T>::const_iterator const_iterator;
	for (const_iterator it = ms.begin(); it != ms.end(); ++it)
		os << *it << '\n';
	return os;
}

#endif
