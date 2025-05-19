/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:03:01 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/19 22:04:21 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "CONSTRUCTOR SIGN GRADE OVER 150 TEST" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	try
	{
		Form lowGrade("lowGrade", 151, 1);
		std::cout << lowGrade << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "[Exception] " << e.what() << std::endl;
	}

	std::cout << "\n";
	std::cout << "CONSTRUCTOR SIGN GRADE BELOW 1 TEST" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	try
	{
		Form highGrade("highGrade", 0, 1);
		std::cout << highGrade << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "[Exception] " << e.what() << std::endl;
	}

	std::cout << "\n";
	std::cout << "CONSTRUCTOR EXECUTE GRADE OVER 150 TEST" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	try
	{
		Form lowGrade("lowGrade", 1, 151);
		std::cout << lowGrade << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "[Exception] " << e.what() << std::endl;
	}

	std::cout << "\n";
	std::cout << "CONSTRUCTOR EXECUTE GRADE BELOW 1 TEST" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	try
	{
		Form highGrade("highGrade", 1, 0);
		std::cout << highGrade << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "[Exception] " << e.what() << std::endl;
	}

	std::cout << "\n";
	std::cout << "FORM SIGN TEST" << std::endl;
	std::cout << "--------------" << std::endl;
	{
		Bureaucrat signer("signer", 1);
		Form toBeSigned("toBeSigned", 1, 1);

		std::cout << toBeSigned << std::endl;
		signer.signForm(toBeSigned);
		std::cout << toBeSigned << std::endl;
	}

	std::cout << "\n";
	std::cout << "FORM ALREADY SIGNED TEST" << std::endl;
	std::cout << "------------------------" << std::endl;
	{
		Bureaucrat signer("signer", 1);
		Form signedForm("signedForm", 1, 1);

		signer.signForm(signedForm);
		signer.signForm(signedForm);
	}

	std::cout << "\n";
	std::cout << "FORM CANNOT BE SIGNED TEST" << std::endl;
	std::cout << "--------------------------" << std::endl;
	{
		Bureaucrat signer("signer", 2);
		Form notSignedForm("notSignedForm", 1, 1);

		signer.signForm(notSignedForm);
	}

	return 0;
}
