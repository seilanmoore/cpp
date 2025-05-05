/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:06:23 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/04 15:51:05 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap " << _name
			  << " default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap " << _name
			  << " parametric constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << _name
			  << " copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this == &other)
		return *this;
	ClapTrap::operator=(other);
	std::cout << "FragTrap " << _name
			  << " assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name
			  << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Fragtrap " << _name
			  << " high-fives successfully" << std::endl;
}
