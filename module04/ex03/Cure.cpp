/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:22:20 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/12 23:03:07 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cerr << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cerr << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this == &other)
		return *this;
	AMateria::operator=(other);
	std::cerr << "Cure assignment operator called" << std::endl;
	return *this;
}

Cure::~Cure(void)
{
	std::cerr << "Cure desctructor called" << std::endl;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}

AMateria *Cure::clone(void) const
{
	return new Cure(*this);
}
