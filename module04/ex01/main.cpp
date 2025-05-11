/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:22:23 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/11 17:29:55 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	Animal *animal[10];

	std::cout << "CONSTRUCTORS" << std::endl
			  << "------------" << std::endl;
	Animal *a = new Animal();
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
	}
	std::cout << std::endl;
	std::cout << "IDEAS" << std::endl;
	std::cout << "-----" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (animal[i]->getType() == "Cat")
			std::cout << "Cat idea is " << dynamic_cast<Cat *>(animal[i])->getIdeas()[i] << std::endl;
		else
			std::cout << "Dog idea is " << dynamic_cast<Dog *>(animal[i])->getIdeas()[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "DESTRUCTORS" << std::endl
			  << "-----------" << std::endl;
	for (int i = 0; i < 10; i++)
		delete animal[i];
	delete a;
	return 0;
}
