/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:21:29 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/11 16:44:34 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog(void) : WrongAnimal("WrongDog")
{
	std::cerr << "WrongDog default constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &other) : WrongAnimal(other)
{
	std::cerr << "WrongDog copy constructor called" << std::endl;
}

WrongDog &WrongDog::operator=(const WrongDog &other)
{
	if (this == &other)
		return *this;
	WrongAnimal::operator=(other);
	std::cerr << "WrongDog assignment operator called" << std::endl;
	return *this;
}

WrongDog::~WrongDog(void)
{
	std::cerr << "Dog destructor called" << std::endl;
}

void WrongDog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}
