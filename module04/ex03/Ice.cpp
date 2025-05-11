/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:22:20 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/11 17:56:05 by smoore-a         ###   ########.fr       */
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
	(void)other;
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
