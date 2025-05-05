/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:52:51 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/04 15:53:47 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("<name>"),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap " << _name
			  << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap " << _name
			  << " parametric constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name),
	  _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints),
	  _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name
			  << " copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this == &other)
		return *this;
	std::cout << "ClapTrap " << _name
			  << " assignment operator called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name
			  << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!_hitPoints)
	{
		std::cout
			<< "ClapTrap " << _name
			<< " cannot attack because is dead" << std::endl;
		return;
	}
	if (!_energyPoints)
	{
		std::cout
			<< "ClapTrap " << _name
			<< " cannot attack because it has no energy points" << std::endl;
		return;
	}
	--_energyPoints;
	std::cout
		<< "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!amount)
		return;
	if (!_hitPoints)
	{
		std::cout << "ClapTrap " << _name << " cannot take damage "
				  << "because is already dead" << std::endl;
		return;
	}
	if (amount <= _hitPoints)
	{
		std::cout
			<< "ClapTrap " << _name << " takes "
			<< amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
		return;
	}
	std::cout
		<< "ClapTrap " << _name << " takes "
		<< _hitPoints << " points of damage!" << std::endl;
	_hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!amount)
		return;
	if (!_hitPoints)
	{
		std::cout
			<< "ClapTrap " << _name
			<< " cannot repair because is dead"
			<< std::endl;
		return;
	}
	if (!_energyPoints)
	{
		std::cout
			<< "ClapTrap " << _name
			<< " cannot repair because it has no energy points"
			<< std::endl;
		return;
	}
	--_energyPoints;
	_hitPoints += amount;
	std::cout
		<< "ClapTrap " << _name << " repairs itself, recovering " << amount
		<< " of hit points!"
		<< std::endl;
}
