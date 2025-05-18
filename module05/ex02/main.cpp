/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:03:01 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/18 16:39:50 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void shrubberyTest()
{
	std::cout << "SHRUBBERY SUCCESSFUL TEST" << std::endl;
	std::cout << "-------------------------" << std::endl;
	{
		AForm *shrubbery;
		try
		{
			Bureaucrat signer("signer", 145);
			Bureaucrat executor("executor", 137);

			shrubbery = new ShrubberyCreationForm("home");
			std::cout << signer << std::endl;
			std::cout << *shrubbery << std::endl;
			signer.signForm(*shrubbery);
			std::cout << executor << std::endl;
			std::cout << *shrubbery << std::endl;
			executor.executeForm(*shrubbery);
			delete shrubbery;
			shrubbery = NULL;
		}
		catch (const std::exception &e)
		{
			std::cerr << "[Exception] " << e.what() << std::endl;
		}
		delete shrubbery;
	}

	std::cout << "\n";
	std::cout << "SHRUBBERY LOW EXECUTOR GRADE TEST" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	{
		AForm *shrubbery;
		try
		{
			Bureaucrat signer("signer", 145);
			Bureaucrat executor("executor", 138);

			shrubbery = new ShrubberyCreationForm("home");
			std::cout << signer << std::endl;
			std::cout << *shrubbery << std::endl;
			signer.signForm(*shrubbery);
			std::cout << executor << std::endl;
			std::cout << *shrubbery << std::endl;
			executor.executeForm(*shrubbery);
			delete shrubbery;
			shrubbery = NULL;
		}
		catch (const std::exception &e)
		{
			std::cerr << "[Exception] " << e.what() << std::endl;
		}
		delete shrubbery;
	}

	std::cout << "\n";
	std::cout << "SHRUBBERY LOW SIGNER GRADE TEST" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	{
		AForm *shrubbery;
		try
		{
			Bureaucrat signer("signer", 146);
			Bureaucrat executor("executor", 137);

			shrubbery = new ShrubberyCreationForm("home");
			std::cout << signer << std::endl;
			std::cout << *shrubbery << std::endl;
			signer.signForm(*shrubbery);
			std::cout << executor << std::endl;
			std::cout << *shrubbery << std::endl;
			executor.executeForm(*shrubbery);
			delete shrubbery;
			shrubbery = NULL;
		}
		catch (const std::exception &e)
		{
			std::cerr << "[Exception] " << e.what() << std::endl;
		}
		delete shrubbery;
	}
}

void robotomyTest()
{
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 10; i >= 0; --i)
	{
		std::cout << "\n";
		std::cout << "ROBOTOMY SUCCESSFUL TEST" << std::endl;
		std::cout << "-------------------------" << std::endl;
		{
			AForm *robotomy;
			try
			{
				Bureaucrat signer("signer", 72);
				Bureaucrat executor("executor", 45);

				robotomy = new RobotomyRequestForm("Timmy");
				std::cout << signer << std::endl;
				std::cout << *robotomy << std::endl;
				signer.signForm(*robotomy);
				std::cout << executor << std::endl;
				std::cout << *robotomy << std::endl;
				executor.executeForm(*robotomy);
				delete robotomy;
				robotomy = NULL;
			}
			catch (const std::exception &e)
			{
				std::cerr << "[Exception] " << e.what() << std::endl;
			}
			delete robotomy;
		}
	}
}

void presidentTest()
{
	std::cout << "\n";
	std::cout << "PRESIDENT SUCCESSFUL TEST" << std::endl;
	std::cout << "-------------------------" << std::endl;
	{
		AForm *pardon;
		try
		{
			Bureaucrat signer("signer", 25);
			Bureaucrat executor("executor", 5);
			pardon = new PresidentialPardonForm("Trump");

			std::cout << signer << std::endl;
			std::cout << *pardon << std::endl;
			signer.signForm(*pardon);
			std::cout << executor << std::endl;
			std::cout << *pardon << std::endl;
			executor.executeForm(*pardon);
			delete pardon;
			pardon = NULL;
		}
		catch (const std::exception &e)
		{
			std::cerr << "[Exception] " << e.what() << std::endl;
		}
		delete pardon;
	}
}

int main()
{
	shrubberyTest();
	robotomyTest();
	presidentTest();
	return 0;
}
