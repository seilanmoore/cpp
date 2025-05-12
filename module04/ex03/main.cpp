/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:22:23 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/12 23:37:27 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

static void testSubjectRequirements()
{
	std::cout << "\n===== SUBJECT REQUIREMENTS TEST =====\n"
			  << std::endl;

	std::cout << "\nLEARN MATERIAS:\n"
			  << std::endl;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\nCREATE ME CHARACTER:\n"
			  << std::endl;
	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\nUSE MATERIA ON BOB:\n"
			  << std::endl;
	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\nEND OF SIMULATION:"
			  << std::endl;
	std::cout << "\nDestruct bob:"
			  << std::endl;
	delete bob;
	std::cout << "\nDestruct me:"
			  << std::endl;
	delete me;
	std::cout << "\nDestruct src:"
			  << std::endl;
	delete src;
}

int main(void)
{
	testSubjectRequirements();
	return 0;
}
