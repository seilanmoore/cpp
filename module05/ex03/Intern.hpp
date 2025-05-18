/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:51:58 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/18 22:43:19 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class AForm;

class Intern
{
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	class InternCreateException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Intern: could not create form";
		}
	};

	AForm *makeForm(
		const std::string &form, const std::string &target);

private:
	typedef AForm *(Intern::*FormCreationMethodPtr)(const std::string &);
	struct FormCreatorEntry
	{
		std::string nameToMatch;
		FormCreationMethodPtr creatorMethod;
	};
	static const FormCreatorEntry _formCreators[];
	AForm *_createRobotomyRequestForm(const std::string &target);
	AForm *_createShrubberyCreationForm(const std::string &target);
	AForm *_createPresidentialPardonForm(const std::string &target);
};

#endif
