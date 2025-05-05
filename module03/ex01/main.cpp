/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:53:42 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/04 12:48:05 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap *jose;
	ScavTrap luis("Luis");
	ScavTrap mario("Mario");

	jose = new ScavTrap("Jose");
	jose->attack("Maria");
	delete jose;
	mario.guardGate();
	luis = mario;
	luis.guardGate();
	return 0;
}
