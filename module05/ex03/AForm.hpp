/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:44:41 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/19 23:36:48 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(const std::string &name, int signGrade, int executeGrade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	const std::string &getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(const Bureaucrat &bureaucrat);

	virtual void execute(Bureaucrat const &executor) const = 0;

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

	class NotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Form is not signed";
		}
	};

	class FileException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Form error handling file";
		}
	};

private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _executeGrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
