/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:45:17 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/19 22:25:51 by smoore-a         ###   ########.fr       */
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
		throw AlreadySignedException();
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form " << form.getName() << ": "
	   << (form.getSigned() ? "signed" : "not signed") << ", "
	   << "sign(" << form.getSignGrade() << "), "
	   << "execute(" << form.getExecuteGrade() << ").";
	return os;
}
