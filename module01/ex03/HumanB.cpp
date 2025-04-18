/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:22:45 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/18 22:23:23 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void) : _name("HumanB"),
					   _weapon(NULL)
{
}

HumanB::HumanB(std::string const &name) : _name(name),
										  _weapon(NULL)
{
}

HumanB::~HumanB(void)
{
}

void HumanB::attack(void) const
{
	if (this->_weapon)
	{
		std::cout << this->_name << " attacks with their "
				  << this->_weapon->getType() << std::endl;
	}
	else
		std::cout << this->_name << " has no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
