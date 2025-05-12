/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:22:20 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/12 23:04:00 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cerr << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cerr << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this == &other)
		return *this;
	AMateria::operator=(other);
	std::cerr << "Ice assignment operator called" << std::endl;
	return *this;
}

Ice::~Ice(void)
{
	std::cerr << "Ice desctructor called" << std::endl;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "
			  << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone(void) const
{
	return new Ice(*this);
}
