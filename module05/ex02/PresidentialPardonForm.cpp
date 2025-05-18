/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 11:01:36 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/18 16:19:34 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("pardon", 25, 5),
												 _target("<target>")
{
	std::cerr << "PresidentialPardonForm default constructor called"
			  << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("pardon", 25, 5),
	  _target(target)
{
	std::cerr << "PresidentialPardonForm default constructor called"
			  << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &other)
	: AForm("pardon", 25, 5),
	  _target(other._target)
{
	std::cerr << "PresidentialPardonForm copy constructor called"
			  << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
	const PresidentialPardonForm &other)
{
	std::cerr << "PresidentialPardonForm assignment operator called"
			  << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cerr << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
			  << std::endl;
}
