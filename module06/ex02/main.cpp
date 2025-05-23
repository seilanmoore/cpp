/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:30:04 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/23 23:48:07 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base *generate()
{
	static bool seeded = false;
	if (!seeded)
	{
		seeded = true;
		std::srand(std::time(0));
	}
	int n = std::rand();
	switch (n % 3)
	{
	case 0:
		// std::cout << "'A' ";
		return new A;
	case 1:
		// std::cout << "'B' ";
		return new B;
	case 2:
		// std::cout << "'C' ";
		return new C;
	}
	return NULL;
}

static void identify(Base *p)
{
	if (!p)
	{
		std::cout << "Pointer is NULL" << std::endl;
		return;
	}
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

static void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << ": not A" << std::endl;
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << ": not B" << std::endl;
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << ": unknown type" << std::endl;
	}
}

int main()
{
	Base *obj;
	for (int i = 10; i > 0; --i)
	{
		std::cout << "OBJECT " << 10 - i << std::endl;
		std::cout << "--------" << std::endl;
		obj = generate();
		Base &ref = *obj;
		identify(obj);
		if (obj)
			identify(ref);
		delete obj;
		std::cout << std::endl;
	}

	std::cout << "NULL POINTER" << std::endl;
	std::cout << "------------" << std::endl;
	Base *nullPtr = generate();
	Base &nullRef = *nullPtr;
	delete nullPtr;
	nullPtr = NULL;
	identify(nullPtr);
	if (nullPtr)
		identify(nullRef);

	std::cout << "\nBASE OBJECT" << std::endl;
	std::cout << "-----------" << std::endl;
	Base *base = new Base;
	Base &baseRef = *base;
	identify(base);
	if (base)
		identify(baseRef);
	delete base;
	base = NULL;
	return 0;
}
