/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:51:51 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/18 17:49:08 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Intern.hpp"

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
	std::cerr << "Intern assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	return *this;
}

Intern::~Intern()
{
	std::cerr << "Intern destructor called" << std::endl;
}

static int getFormType(const std::string &form)
{
	const std::string formType[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"};

	for (int i = 0; i < 3; i++)
	{
		if (form == formType[i])
			return i;
	}
	return -1;
}

AForm *Intern::makeForm(
	const std::string &form, const std::string &target) const
{
	switch (getFormType(form))
	{
	case 0:
	{
		std::cout << "Intern creates " << form << "." << std::endl;
		return new ShrubberyCreationForm(target);
	}
	case 1:
	{
		std::cout << "Intern creates " << form << "." << std::endl;
		return new RobotomyRequestForm(target);
	}
	case 2:
	{
		std::cout << "Intern creates " << form << "." << std::endl;
		return new PresidentialPardonForm(target);
	}
	default:
	{
		std::cout << "Intern could not create "
				  << form << "." << std::endl;
		return NULL;
	}
	}
}
