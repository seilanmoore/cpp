/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:48:43 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/18 16:19:45 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy", 72, 45),
											 _target("<target>")
{
	std::cerr << "RobotomyRequestForm default constructor called"
			  << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("robotomy", 72, 45),
	  _target(target)
{
	std::cerr << "RobotomyRequestForm default constructor called"
			  << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(
	const RobotomyRequestForm &other)
	: AForm("robotomy", 72, 45),
	  _target(other._target)
{
	std::cerr << "RobotomyRequestForm copy constructor called"
			  << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
	const RobotomyRequestForm &other)
{
	std::cerr << "RobotomyRequestForm assignment operator called"
			  << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cerr << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	std::cout << "* some drilling noises *" << std::endl;
	if (rand() % 2)
		std::cout << _target << " escaped." << std::endl;
	else
	{
		std::cout << _target << " has been robotomized successfully."
				  << std::endl;
	}
}
