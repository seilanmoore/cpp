/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:51:51 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/19 23:58:36 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cerr << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cerr << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cerr << "Intern assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cerr << "Intern destructor called" << std::endl;
}

const Intern::FormCreatorEntry Intern::_formCreators[] = {
	{"ShrubberyCreationForm", &Intern::_createShrubberyCreationForm},
	{"RobotomyRequestForm", &Intern::_createRobotomyRequestForm},
	{"PresidentialPardonForm", &Intern::_createPresidentialPardonForm}};

AForm *Intern::makeForm(
	const std::string &formName, const std::string &formTarget)
{
	const int numForm = sizeof(_formCreators) / sizeof(_formCreators[0]);
	for (int i = 0; i < numForm; ++i)
	{
		if (formName == _formCreators[i].nameToMatch)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*_formCreators[i].creatorMethod)(formTarget);
		}
	}
	throw InternCreateException();
}

AForm *Intern::_createRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::_createShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::_createPresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}
