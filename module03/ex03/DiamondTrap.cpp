/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:06:23 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/04 23:01:38 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("<name>_clap_name"),
								 ScavTrap(),
								 FragTrap()
{
	_name = "<name>";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << _name
			  << " default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"),
													ScavTrap(name),
													FragTrap(name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << _name
			  << " parametric constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other),
													 ScavTrap(other),
													 FragTrap(other)
{
	std::cout << "DiamondTrap " << _name
			  << " copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this == &other)
		return *this;
	ClapTrap::operator=(other);
	ScavTrap::operator=(other);
	FragTrap::operator=(other);
	std::cout << "DiamondTrap " << _name
			  << " assignment operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name
			  << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << _name
			  << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
