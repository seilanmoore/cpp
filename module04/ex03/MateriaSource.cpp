/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:23:45 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/11 17:44:44 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cerr << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_template[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cerr << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._template[i])
			_template[i] = other._template[i]->clone();
		else
			_template[i] = 0;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this == &other)
		return *this;
	std::cerr << "MateriaSource assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete _template[i];
		if (other._template[i])
			_template[i] = other._template[i]->clone();
		else
			_template[i] = 0;
	}
	return *this;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		delete _template[i];
	std::cerr << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_template[i])
		{
			_template[i] = m;
			std::cerr << "Materia " << m->getType()
					  << " has been learned" << std::endl;
			return;
		}
	}
	std::cerr << "There is no room left for more materias" << std::endl;
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_template[i] && _template[i]->getType() == type)
			return _template[i]->clone();
	}
	std::cerr << "Materia " << type
			  << " has been not learned yet" << std::endl;
	return 0;
}
