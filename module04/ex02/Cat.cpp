/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:21:19 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/11 17:18:31 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
	std::cerr << "Cat default constructor called" << std::endl;
	_brain = new Brain("...fish...");
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cerr << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return *this;
	AAnimal::operator=(other);
	std::cerr << "Cat assignment operator called" << std::endl;
	delete _brain;
	_brain = new Brain(*other._brain);
	return *this;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cerr << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

const std::string *Cat::getIdeas(void) const
{
	return _brain->getIdeas();
}
