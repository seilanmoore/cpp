/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:11:49 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/18 17:01:37 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : name_("Paco")
{
}

Zombie::Zombie(std::string const &name) : name_(name)
{
}

Zombie::~Zombie(void)
{
	std::cout << this->name_ << ": has been destroyed" << std::endl;
}

void Zombie::setName(std::string const &name)
{
	this->name_ = name;
}

void Zombie::announce(void) const
{
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
