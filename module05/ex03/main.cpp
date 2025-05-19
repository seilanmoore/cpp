/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:03:01 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/19 23:56:12 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

void shrubberyTest()
{
	std::cout << "INTERN SHRUBBERY SUCCESSFUL TEST" << std::endl;
	std::cout << "--------------------------------" << std::endl;

	Intern some;
	AForm *scf = NULL;
	try
	{
		scf = some.makeForm("ShrubberyCreationForm", "home");
		Bureaucrat signer("signer", 145);
		Bureaucrat executor("executor", 137);

		std::cout << signer << std::endl;
		std::cout << *scf << std::endl;
		signer.signForm(*scf);
		std::cout << executor << std::endl;
		std::cout << *scf << std::endl;
		executor.executeForm(*scf);
		delete scf;
		scf = NULL;
	}
	catch (const std::exception &e)
	{
		std::cerr << "[Exception] " << e.what() << std::endl;
	}
	delete scf;
}

void robotomyTest()
{
	for (int i = 10; i > 0; --i)
	{
		std::cout << "\n";
		std::cout << "ROBOTOMY SUCCESSFUL TEST" << std::endl;
		std::cout << "-------------------------" << std::endl;
		{
			Intern some;
			AForm *rrf = NULL;
			try
			{
				rrf = some.makeForm("RobotomyRequestForm", "Timmy");
				Bureaucrat signer("signer", 72);
				Bureaucrat executor("executor", 45);

				std::cout << signer << std::endl;
				std::cout << *rrf << std::endl;
				signer.signForm(*rrf);
				std::cout << executor << std::endl;
				std::cout << *rrf << std::endl;
				executor.executeForm(*rrf);
				delete rrf;
				rrf = NULL;
			}
			catch (const std::exception &e)
			{
				std::cerr << "[Exception] " << e.what() << std::endl;
			}
			delete rrf;
		}
	}
}

void pardonTest()
{
	std::cout << "\n";
	std::cout << "INTERN PARDON SUCCESSFUL TEST" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	Intern some;
	AForm *ppf = NULL;
	try
	{
		ppf = some.makeForm("PresidentialPardonForm", "Trump");
		Bureaucrat signer("signer", 25);
		Bureaucrat executor("executor", 5);

		std::cout << signer << std::endl;
		std::cout << *ppf << std::endl;
		signer.signForm(*ppf);
		std::cout << executor << std::endl;
		std::cout << *ppf << std::endl;
		executor.executeForm(*ppf);
		delete ppf;
		ppf = NULL;
	}
	catch (const std::exception &e)
	{
		std::cerr << "[Exception] " << e.what() << std::endl;
	}
	delete ppf;
}

void failTest()
{
	std::cout << "\n";
	std::cout << "INTERN FAILING TEST" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	Intern some;
	AForm *ppf = NULL;
	try
	{
		ppf = some.makeForm("NoForm", "NoTarget");
		Bureaucrat signer("signer", 25);
		Bureaucrat executor("executor", 5);

		std::cout << signer << std::endl;
		std::cout << *ppf << std::endl;
		signer.signForm(*ppf);
		std::cout << executor << std::endl;
		std::cout << *ppf << std::endl;
		executor.executeForm(*ppf);
		delete ppf;
		ppf = NULL;
	}
	catch (const std::exception &e)
	{
		std::cerr << "[Exception] " << e.what() << std::endl;
	}
	delete ppf;
}

int main()
{
	shrubberyTest();
	robotomyTest();
	pardonTest();
	failTest();
	return 0;
}
