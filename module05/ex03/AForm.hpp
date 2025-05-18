/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:44:41 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/18 15:30:22 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
#define A_FORM_HPP

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

	class AFormException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "AForm exception";
		}
	};

	class GradeTooHighException : public AFormException
	{
	public:
		virtual const char *what() const throw()
		{
			return "AForm: grade too high";
		}
	};

	class GradeTooLowException : public AFormException
	{
	public:
		virtual const char *what() const throw()
		{
			return "AForm: grade too low";
		}
	};

	class AlreadySignedException : public AFormException
	{
	public:
		virtual const char *what() const throw()
		{
			return "Form: already signed";
		}
	};

	class FormNotSignedException : public AFormException
	{
	public:
		virtual const char *what() const throw()
		{
			return "AForm: form not signed";
		}
	};

	class FileException : public AFormException
	{
	public:
		virtual const char *what() const throw()
		{
			return "AForm: error handling file";
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
