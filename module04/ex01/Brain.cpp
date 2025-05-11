/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:21:09 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/11 17:12:24 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cerr << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "idea";
}

Brain::Brain(const std::string &idea)
{
	std::cerr << "Brain parametric constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = idea;
}

Brain::Brain(const Brain &other)
{
	std::cerr << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	if (this == &other)
		return *this;
	std::cerr << "Brain assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	return *this;
}

Brain::~Brain(void)
{
	std::cerr << "Brain destructor called" << std::endl;
}

const std::string *Brain::getIdeas(void) const
{
	return _ideas;
}
