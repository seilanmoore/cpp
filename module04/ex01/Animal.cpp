/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:21:09 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/11 17:03:03 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("")
{
	std::cerr << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cerr << "Animal parametric constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cerr << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this == &other)
		return *this;
	std::cerr << "Animal assignment operator called" << std::endl;
	_type = other._type;
	return *this;
}

Animal::~Animal(void)
{
	std::cerr << "Animal destructor called" << std::endl;
}

const std::string &Animal::getType(void) const
{
	return _type;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal sound!" << std::endl;
}
