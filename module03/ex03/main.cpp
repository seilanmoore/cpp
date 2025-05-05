/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:53:42 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/04 23:10:59 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap carlos("Carlos");

	carlos.whoAmI();
	for (int i = 0; i < 49; i++)
		carlos.attack("Jesus");
	carlos.attack("Jesus");
	carlos.attack("Jesus");
	carlos.guardGate();
	carlos.guardGate();
	carlos.highFivesGuys();
	carlos.takeDamage(149);
	carlos.attack("Jesus");
	return 0;
}
