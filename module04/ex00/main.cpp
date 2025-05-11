/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:22:23 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/11 17:25:32 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "ANIMAL EXAMPLE" << std::endl;
	std::cout << "--------------" << std::endl;
	{
		const Animal *obj = new Animal();

		obj->makeSound();
		delete obj;
		std::cout << std::endl;
	}
	std::cout << "CAT EXAMPLE" << std::endl;
	std::cout << "-----------" << std::endl;
	{
		const Animal *obj = new Cat();

		std::cout << obj->getType() << " " << std::endl;
		obj->makeSound();
		delete obj;
		std::cout << std::endl;
	}
	std::cout << "DOG EXAMPLE" << std::endl;
	std::cout << "-----------" << std::endl;
	{
		const Animal *obj = new Dog();

		std::cout << obj->getType() << " " << std::endl;
		obj->makeSound();
		delete obj;
		std::cout << std::endl;
	}
	std::cout << "WRONG_ANIMAL EXAMPLE" << std::endl;
	std::cout << "--------------------" << std::endl;
	{
		const WrongAnimal *obj = new WrongAnimal();

		obj->makeSound();
		delete obj;
		std::cout << std::endl;
	}
	std::cout << "WRONG_CAT EXAMPLE" << std::endl;
	std::cout << "-----------------" << std::endl;
	{
		const WrongAnimal *obj = new WrongCat();

		std::cout << obj->getType() << " " << std::endl;
		obj->makeSound();
		delete obj;
		std::cout << std::endl;
	}
	std::cout << "WRONG_DOG EXAMPLE" << std::endl;
	std::cout << "-----------------" << std::endl;
	{
		const WrongAnimal *obj = new WrongDog();

		std::cout << obj->getType() << " " << std::endl;
		obj->makeSound();
		delete obj;
		std::cout << std::endl;
	}
	return 0;
}
