/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:14:51 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/18 17:03:28 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(const int n, std::string const &name)
{
	Zombie *zombie;

	zombie = new Zombie[n];
	for (int i = 0; i < n; i++)
		zombie[i].setName(name);
	return zombie;
}
