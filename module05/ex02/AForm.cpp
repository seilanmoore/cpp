/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:45:17 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/20 22:21:03 by smoore-a         ###   ########.fr       */
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
		throw AlreadySignedException();
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Form grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form grade requirement not met or "
		   "grade out of bounds (too low)";
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return "Form is already signed";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form is not signed";
}

const char *AForm::FileException::what() const throw()
{
	return "Form error handling file";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form " << form.getName() << ": "
	   << (form.getSigned() ? "signed" : "not signed") << ", "
	   << "sign(" << form.getSignGrade() << "), "
	   << "execute(" << form.getExecuteGrade() << ").";
	return os;
}
