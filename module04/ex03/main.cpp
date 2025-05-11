/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:22:23 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/11 18:04:48 by smoore-a         ###   ########.fr       */
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

static void testMateriaSource()
{
	std::cout << "\n===== MATERIA SOURCE TEST =====\n"
			  << std::endl;

	// Test learning multiple materias
	MateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Test learning too many materias
	AMateria *tmp = new Ice();
	src->learnMateria(tmp); // Should fail, already 4 materias

	// Test creating different materias
	AMateria *m1 = src->createMateria("ice");
	AMateria *m2 = src->createMateria("cure");
	AMateria *m3 = src->createMateria("unknown"); // Should return NULL

	if (m1)
		std::cout << "Successfully created ice materia: " << m1->getType() << std::endl;
	if (m2)
		std::cout << "Successfully created cure materia: " << m2->getType() << std::endl;
	if (m3)
		std::cout << "Created unknown materia: " << m3->getType() << std::endl;
	else
		std::cout << "Failed to create unknown materia (expected)" << std::endl;

	// Test deep copy through copy constructor
	MateriaSource *srcCopy = new MateriaSource(*src);
	AMateria *m4 = srcCopy->createMateria("ice");
	AMateria *m5 = srcCopy->createMateria("cure");

	if (m4 && m5)
		std::cout << "Copy constructor created a working copy of MateriaSource" << std::endl;

	// Clean up
	delete m1;
	delete m2;
	delete m4;
	delete m5;
	delete src;
	delete srcCopy;
	delete tmp;
}

static void testCharacter()
{
	std::cout << "\n===== CHARACTER TEST =====\n"
			  << std::endl;

	// Create character and materias
	Character *cloud = new Character("Cloud");
	AMateria *ice1 = new Ice();
	AMateria *ice2 = new Ice();
	AMateria *cure1 = new Cure();
	AMateria *cure2 = new Cure();
	AMateria *cure3 = new Cure();

	// Test equipping materias
	std::cout << "Testing equip:" << std::endl;
	cloud->equip(ice1);
	cloud->equip(cure1);
	cloud->equip(ice2);
	cloud->equip(cure2);
	cloud->equip(cure3); // Should fail, inventory full

	// Test using materias
	ICharacter *sephiroth = new Character("Sephiroth");
	std::cout << "\nTesting use:" << std::endl;
	cloud->use(0, *sephiroth);
	cloud->use(1, *sephiroth);
	cloud->use(2, *sephiroth);
	cloud->use(3, *sephiroth);
	cloud->use(4, *sephiroth);	// Should fail, invalid index
	cloud->use(-1, *sephiroth); // Should fail, invalid index

	// Test unequipping
	std::cout << "\nTesting unequip:" << std::endl;
	cloud->unequip(1);
	cloud->use(1, *sephiroth); // Should fail, no materia at index 1 now
	cloud->equip(cure3);	   // Should succeed now that a slot is open
	cloud->use(1, *sephiroth); // Should work again

	// Test deep copy through copy constructor
	std::cout << "\nTesting deep copy with copy constructor:" << std::endl;
	Character *cloudCopy = new Character(*cloud);
	std::cout << "Original character: " << cloud->getName() << std::endl;
	std::cout << "Copied character: " << cloudCopy->getName() << std::endl;

	// Verify copy uses different materia pointers (deep copy)
	std::cout << "Using copied character's materias:" << std::endl;
	cloudCopy->use(0, *sephiroth);
	cloudCopy->use(1, *sephiroth);
	cloudCopy->use(2, *sephiroth);
	cloudCopy->use(3, *sephiroth);

	// Verify that changing one doesn't affect the other
	std::cout << "\nUnequipping from original doesn't affect copy:" << std::endl;
	cloud->unequip(0);
	cloud->use(0, *sephiroth);	   // Should fail
	cloudCopy->use(0, *sephiroth); // Should still work

	// Test assignment operator
	std::cout << "\nTesting assignment operator:" << std::endl;
	Character *tifa = new Character("Tifa");
	*tifa = *cloud;
	std::cout << "Original character: " << cloud->getName() << std::endl;
	std::cout << "Assigned character: " << tifa->getName() << std::endl;

	// Clean up (note we don't delete unequipped materias here as they should be handled in a real program)
	delete cure1; // This was unequipped, so we need to delete it manually
	delete ice1;  // This was unequipped, so we need to delete it manually
	delete cloud;
	delete cloudCopy;
	delete tifa;
	delete sephiroth;
}

static void testPolymorphism()
{
	std::cout << "\n===== POLYMORPHISM TEST =====\n"
			  << std::endl;

	// Test AMateria abstract class and polymorphism
	std::cout << "Testing polymorphic behavior through interfaces:" << std::endl;

	// Create objects through interfaces
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *hero = new Character("Hero");
	ICharacter *enemy = new Character("Enemy");

	// Create materias through interface
	AMateria *m1 = src->createMateria("ice");
	AMateria *m2 = src->createMateria("cure");

	// Use polymorphic functions
	hero->equip(m1);
	hero->equip(m2);

	std::cout << "Using materias through interfaces:" << std::endl;
	hero->use(0, *enemy);
	hero->use(1, *enemy);

	// Clean up
	delete hero;
	delete enemy;
	delete src;
}

int main(void)
{
	testSubjectRequirements();
	testMateriaSource();
	testCharacter();
	testPolymorphism();
	return 0;
}
