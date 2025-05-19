/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:44:41 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/19 22:11:05 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
public:
	Form();
	Form(const std::string &name, int signGrade, int executeGrade);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	const std::string &getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Form grade is too high";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Form grade requirement not met or "
				   "grade out of bounds (too low)";
		}
	};

	class AlreadySignedException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Form is already signed";
		}
	};

private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _executeGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
