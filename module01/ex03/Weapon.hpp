/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:48:51 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/23 12:55:18 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
public:
	Weapon(void);
	Weapon(std::string const &type);
	~Weapon(void);
	const std::string &getType(void) const;
	void setType(std::string const &type);

private:
	std::string _type;
};

#endif
