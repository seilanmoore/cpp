/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:21:29 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/11 17:09:41 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cerr << "Dog default constructor called" << std::endl;
	_brain = new Brain("...meat...");
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cerr << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return *this;
	Animal::operator=(other);
	std::cerr << "Dog assignment operator called" << std::endl;
	delete _brain;
	_brain = new Brain(*other._brain);
	return *this;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cerr << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}

const std::string *Dog::getIdeas(void) const
{
	return _brain->getIdeas();
}
