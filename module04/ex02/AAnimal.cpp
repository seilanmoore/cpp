/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:21:09 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/11 17:15:18 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("")
{
	std::cerr << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string &type) : _type(type)
{
	std::cerr << "AAnimal parametric constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type)
{
	std::cerr << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this == &other)
		return *this;
	std::cerr << "AAnimal assignment operator called" << std::endl;
	_type = other._type;
	return *this;
}

AAnimal::~AAnimal(void)
{
	std::cerr << "AAnimal destructor called" << std::endl;
}

const std::string &AAnimal::getType(void) const
{
	return _type;
}
