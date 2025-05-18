/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:45:17 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/18 15:41:52 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("<name>"),
			   _signed(false),
			   _signGrade(1),
			   _executeGrade(1)
{
	std::cerr << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, int signGrade, int executeGrade)
	: _name(name),
	  _signed(false),
	  _signGrade(signGrade),
	  _executeGrade(executeGrade)
{
	std::cerr << "Form parametric constructor called" << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name),
	  _signed(other._signed),
	  _signGrade(other._signGrade),
	  _executeGrade(other._executeGrade)
{
	std::cerr << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cerr << "Form assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	_signed = other._signed;
	return *this;
}

Form::~Form()
{
	std::cerr << "Form destructor called" << std::endl;
}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecuteGrade() const
{
	return _executeGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
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

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form " << form.getName() << ": " << std::endl;
	if (form.getSigned())
		os << " - Form is signed." << std::endl;
	else
		os << " - Form is not signed." << std::endl;
	os << " - Form grade required to sign: "
	   << form.getSignGrade() << "." << std::endl;
	os << " - Form grade required to execute: "
	   << form.getExecuteGrade() << ".";
	return os;
}
