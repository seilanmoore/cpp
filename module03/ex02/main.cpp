/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:53:42 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/04 14:35:12 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap pepe("Pepe");
	ClapTrap *ivan;

	pepe.highFivesGuys();
	ivan = new FragTrap("Ivan");
	ivan->attack("Carlos");
	delete ivan;
	return 0;
}
