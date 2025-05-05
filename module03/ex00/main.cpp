/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:53:42 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/03 22:45:22 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap paco("Paco");

	paco.attack("Jose");
	paco.takeDamage(4);
	paco.beRepaired(6);
	for (int i = 0; i < 10; i++)
		paco.beRepaired(1);
	paco.takeDamage(50);
	paco.attack("Jose");
	paco.beRepaired(5);
	paco.takeDamage(10);
	return 0;
}
