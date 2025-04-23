/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:52:17 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/23 12:55:06 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : _type("Default")
{
}

Weapon::Weapon(std::string const &type) : _type(type)
{
}

Weapon::~Weapon(void)
{
}

const std::string &Weapon::getType(void) const
{
	return this->_type;
}

void Weapon::setType(std::string const &type)
{
	this->_type = type;
}
