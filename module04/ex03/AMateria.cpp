/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:25:28 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/12 23:00:55 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("")
{
	std::cerr << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string &type) : _type(type)
{
	std::cerr << "AMateria parametric constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{
	std::cerr << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this == &other)
		return *this;
	std::cerr << "AMateria assignment operator called" << std::endl;
	_type = other._type;
	return *this;
}

AMateria::~AMateria(void)
{
	std::cerr << "AMateria destructor called" << std::endl;
}

const std::string &AMateria::getType(void) const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
