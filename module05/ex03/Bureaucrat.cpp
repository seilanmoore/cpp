/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:55:43 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/18 16:41:24 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("<name>"), _grade(150)
{
	std::cerr << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name),
															 _grade(grade)
{
	std::cerr << "Bureaucrat parametric constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name),
												  _grade(other._grade)
{
	std::cerr << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cerr << "Bureaucrat assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cerr << "Bureaucrat destructor called" << std::endl;
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat grade incremented" << std::endl;
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat grade decremented" << std::endl;
	++_grade;
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception &e)
	{
		std::cerr << "[Exception] " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName()
				  << "." << std::endl;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cout << _name << "(" << _grade << ")" << " couldn't execute "
				  << form.getName() << "(" << form.getExecuteGrade() << ")"
				  << std::endl;
		std::cerr << "[Exception] " << e.what() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << _name << " couldn't execute "
				  << form.getName() << std::endl;
		std::cerr << "[Exception] " << e.what() << '\n';
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade "
	   << bureaucrat.getGrade() << ".";
	return os;
}
