/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:22:04 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/18 16:19:55 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery", 145, 137),
												 _target("<target>")
{
	std::cerr << "ShrubberyCreationForm default constructor called"
			  << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("shrubbery", 145, 137),
	  _target(target)
{
	std::cerr << "ShrubberyCreationForm default constructor called"
			  << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm &other)
	: AForm("shrubbery", 145, 137),
	  _target(other._target)
{
	std::cerr << "ShrubberyCreationForm copy constructor called"
			  << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm &other)
{
	std::cerr << "ShrubberyCreationForm assignment operator called"
			  << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cerr << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	std::ofstream outfile((_target + "_shrubbery").c_str(),
						  std::ios::out | std::ios::app);
	if (!outfile.is_open())
		throw FileException();
	outfile << "    /\\\n";
	outfile << "   /  \\\n";
	outfile << "  /    \\\n";
	outfile << " /______\\\n";
	outfile << "    ||\n";
	outfile.close();
}
