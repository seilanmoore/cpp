/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:03:01 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/19 22:00:30 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "CONSTRUCTOR OVER 150 TEST" << std::endl;
	std::cout << "----------------------" << std::endl;
	try
	{
		Bureaucrat paco("Paco", 151);
		std::cout << paco << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "[Exception] " << e.what() << std::endl;
	}

	std::cout << "\n";
	std::cout << "CONSTRUCTOR BELOW 1 TEST" << std::endl;
	std::cout << "----------------------" << std::endl;
	try
	{
		Bureaucrat paco("Paco", 0);
		std::cout << paco << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "[Exception] " << e.what() << std::endl;
	}

	std::cout << "\n";
	std::cout << "INCREMENT BELOW 1 TEST" << std::endl;
	std::cout << "----------------------" << std::endl;
	try
	{
		Bureaucrat paco("Paco", 1);
		std::cout << paco << std::endl;

		paco.decrementGrade();
		std::cout << paco << std::endl;

		paco.incrementGrade();
		std::cout << paco << std::endl;

		paco.incrementGrade();
		std::cout << paco << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "[Exception] " << e.what() << std::endl;
	}

	{
		std::cout << "\n";
		std::cout << "DECREMENT OVER 150 TEST" << std::endl;
		std::cout << "-----------------------" << std::endl;
		Bureaucrat *paco = NULL;
		try
		{
			paco = new Bureaucrat("Paco", 150);
			std::cout << *paco << std::endl;

			std::cout << "\n";
			paco->incrementGrade();
			std::cout << *paco << std::endl;

			std::cout << "\n";
			paco->decrementGrade();
			std::cout << *paco << std::endl;

			std::cout << "\n";
			paco->decrementGrade();
			std::cout << *paco << std::endl;

			delete paco;
			paco = NULL;
		}
		catch (const std::exception &e)
		{
			std::cerr << "[Exception] " << e.what() << std::endl;
		}

		delete paco;
		paco = NULL;
	}
	return 0;
}
