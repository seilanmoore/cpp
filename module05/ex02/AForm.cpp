/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:45:17 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/18 16:41:03 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("<name>"),
			   _signed(false),
			   _signGrade(1),
			   _executeGrade(1)
{
	std::cerr << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
	: _name(name),
	  _signed(false),
	  _signGrade(signGrade),
	  _executeGrade(executeGrade)
{
	std::cerr << "AForm parametric constructor called" << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name),
	  _signed(other._signed),
	  _signGrade(other._signGrade),
	  _executeGrade(other._executeGrade)
{
	std::cerr << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cerr << "AForm assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	_signed = other._signed;
	return *this;
}

AForm::~AForm()
{
	std::cerr << "AForm destructor called" << std::endl;
}

const std::string &AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecuteGrade() const
{
	return _executeGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (_signed)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << _name
				  << " because is already signed." << std::endl;
		throw AlreadySignedException();
	}
	if (bureaucrat.getGrade() > _signGrade)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << _name
				  << " because its grade is too low." << std::endl;
		throw GradeTooLowException();
	}
	_signed = true;
	std::cout << bureaucrat.getName() << " signed "
			  << _name << "." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
	os << "AForm " << AForm.getName() << ": ";
	if (AForm.getSigned())
		os << "signed, ";
	else
		os << "not signed, ";
	os << "sign("
	   << AForm.getSignGrade() << "), ";
	os << "execute("
	   << AForm.getExecuteGrade() << ").";
	return os;
}
