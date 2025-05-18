/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:55:48 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/17 20:04:02 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <fstream>

#include "Form.hpp"

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	const std::string &getName() const;
	int getGrade() const;

	void signForm(Form &form) const;

	void incrementGrade();
	void decrementGrade();

	class BureaucratException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Bureaucrat exception";
		}
	};

	class GradeTooHighException : public BureaucratException
	{
	public:
		virtual const char *what() const throw()
		{
			return "Bureaucrat: grade too high";
		}
	};

	class GradeTooLowException : public BureaucratException
	{
	public:
		virtual const char *what() const throw()
		{
			return "Bureaucrat: grade too low";
		}
	};

private:
	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
