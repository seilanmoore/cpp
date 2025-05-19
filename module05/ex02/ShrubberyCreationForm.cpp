/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:22:04 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/19 23:41:59 by smoore-a         ###   ########.fr       */
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
		throw NotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	std::ofstream outfile((_target + "_shrubbery").c_str(),
						  std::ios::out | std::ios::app);
	if (!outfile.is_open())
		throw FileException();
	outfile << "               ,@@@@@@@," << std::endl;
	outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	outfile << "       |o|        | |         | |" << std::endl;
	outfile << "       |.|        | |         | |" << std::endl;
	outfile << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	outfile.close();
	std::cout << "Shrubbery created at "
			  << this->_target << "_shrubbery" << std::endl;
}
