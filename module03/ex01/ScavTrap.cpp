/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:06:23 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/04 15:54:46 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap " << _name
			  << " default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardGate = false;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << _name
			  << " parametric constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardGate = false;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << _name
			  << " copy constructor called" << std::endl;
	_guardGate = other._guardGate;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this == &other)
		return *this;
	ClapTrap::operator=(other);
	std::cout << "ScavTrap " << _name
			  << " assignment operator called" << std::endl;
	_guardGate = other._guardGate;
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name
			  << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (!_hitPoints)
	{
		std::cout
			<< "ScavTrap " << _name
			<< " cannot attack because is dead" << std::endl;
		return;
	}
	if (!_energyPoints)
	{
		std::cout
			<< "ScavTrap " << _name
			<< " cannot attack because it has no energy points" << std::endl;
		return;
	}
	--_energyPoints;
	std::cout
		<< "ScavTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (!_guardGate)
	{
		std::cout << "ScavTrap " << _name
				  << " is now in Gate keeper mode" << std::endl;
		_guardGate = true;
	}
	else
		std::cout << "ScavTrap " << _name
				  << " is already in Gate keeper mode" << std::endl;
}
