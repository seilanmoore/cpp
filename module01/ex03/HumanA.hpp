/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:04:18 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/18 22:22:38 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
#define HUMAN_A_H

#include <iostream>

#include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string const &name, Weapon &weapon);
	~HumanA(void);
	void attack(void) const;

private:
	std::string _name;
	Weapon &_weapon;
};

#endif
