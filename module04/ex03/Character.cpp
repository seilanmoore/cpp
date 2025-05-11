/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:24:18 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/11 18:00:25 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("")
{
	std::cerr << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(const std::string &name) : _name(name)
{
	std::cerr << "Character parametric constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(const Character &other) : _name(other._name)
{
	std::cerr << "Character copy constructor called" << std::endl;
	copyInventory(other);
}

Character &Character::operator=(const Character &other)
{
	if (this == &other)
		return *this;
	std::cerr << "Character assignment operator called" << std::endl;
	_name = other._name;
	clearInventory();
	copyInventory(other);
	return *this;
}

Character::~Character(void)
{
	clearInventory();
	std::cerr << "Character destructor called" << std::endl;
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cerr << "Materia unknown. Please learn and create a new one"
				  << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cerr << _name << " equipped " << m->getType()
					  << " materia in slot " << i << std::endl;
			return;
		}
	}
	std::cerr << _name << " cannot equip " << m->getType()
			  << " materia because inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		std::cerr << "Slots are 0 to 3. Enter a correct one" << std::endl;
	else if (!_inventory[idx])
	{
		std::cerr << _name << " has no materia equipped in slot "
				  << idx << std::endl;
	}
	else
	{
		std::cerr << _name << " unequipped " << _inventory[idx]->getType()
				  << " materia in slot " << idx << std::endl;
		_inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
		std::cerr << "Slots are 0 to 3. Enter a correct one" << std::endl;
	else if (!_inventory[idx])
	{
		std::cerr << _name << " has no materia equipped in slot "
				  << idx << std::endl;
	}
	else
		_inventory[idx]->use(target);
}

void Character::clearInventory(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = 0;
		}
	}
}

void Character::copyInventory(const Character &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}
