/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:21:23 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/23 07:16:31 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 2;
	}
	ScalarConverter::convert(static_cast<std::string>(argv[1]));

	// Tests
	/* (void)argc;
	(void)argv;
	std::cout << "TESTS" << std::endl;
	std::cout << "-----" << std::endl;

	std::string str;
	std::cout << (str = "\n./convert 0") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("0");

	std::cout << (str = "\n./convert nan") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("nan");

	std::cout << (str = "\n./convert 42.0f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("42.0f");

	// I. Char Literals
	std::cout << (str = "\n./convert 'c'") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("'c'");

	std::cout << (str = "\n./convert '0'") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("'0'");

	std::cout << (str = "\n./convert '*'") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("'*'");

	std::cout << (str = "\n./convert 'A'") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("'A'");

	// For a literal tab character. In C++ string, \t is a tab.
	std::cout << (str = "\n./convert '\\t'") << std::endl; // Input string is quote, tab, quote
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("'\t'");

	// II. Int Literals
	std::cout << (str = "\n./convert 0") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("0");

	std::cout << (str = "\n./convert 42") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("42");

	std::cout << (str = "\n./convert -42") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("-42");

	std::cout << (str = "\n./convert 2147483647") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("2147483647");

	std::cout << (str = "\n./convert -2147483648") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("-2147483648");

	std::cout << (str = "\n./convert 127") << std::endl; // char DEL (non-displayable)
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("127");

	std::cout << (str = "\n./convert 128") << std::endl; // char overflow for signed char
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("128");

	std::cout << (str = "\n./convert -129") << std::endl; // char underflow for signed char
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("-129");

	std::cout << (str = "\n./convert 7") << std::endl; // char Bell (non-displayable)
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("7");

	std::cout << (str = "\n./convert 32") << std::endl; // char Space (displayable)
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("32");

	// III. Float Literals
	std::cout << (str = "\n./convert 0.0f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("0.0f");

	std::cout << (str = "\n./convert 42.0f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("42.0f");

	std::cout << (str = "\n./convert -4.2f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("-4.2f");

	std::cout << (str = "\n./convert 4.2f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("4.2f");

	std::cout << (str = "\n./convert nanf") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("nanf");

	std::cout << (str = "\n./convert inff") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("inff");

	std::cout << (str = "\n./convert +inff") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("+inff");

	std::cout << (str = "\n./convert -inff") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("-inff");

	std::cout << (str = "\n./convert 1.234567f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("1.234567f");

	std::cout << (str = "\n./convert 2147483647.0f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("2147483647.0f");

	std::cout << (str = "\n./convert 1e10f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("1e10f");

	std::cout << (str = "\n./convert 3.402823466e+38f") << std::endl; // Approx FLT_MAX
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("3.402823466e+38f");

	std::cout << (str = "\n./convert 123456789123456789.0f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("123456789123456789.0f");

	// IV. Double Literals
	std::cout << (str = "\n./convert 0.0") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("0.0");

	std::cout << (str = "\n./convert 42.0") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("42.0");

	std::cout << (str = "\n./convert -4.2") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("-4.2");

	std::cout << (str = "\n./convert 4.2") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("4.2");

	std::cout << (str = "\n./convert nan") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("nan");

	std::cout << (str = "\n./convert inf") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("inf");

	std::cout << (str = "\n./convert +inf") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("+inf");

	std::cout << (str = "\n./convert -inf") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("-inf");

	std::cout << (str = "\n./convert 1.234567") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("1.234567");

	std::cout << (str = "\n./convert 2147483647.0") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("2147483647.0");

	std::cout << (str = "\n./convert -2147483648.0") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("-2147483648.0");

	std::cout << (str = "\n./convert 1e20") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("1e20");

	std::cout << (str = "\n./convert 1.79769e+308") << std::endl; // Approx DBL_MAX
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("1.79769e+308");

	std::cout << (str = "\n./convert 123456789123456789.0") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("123456789123456789.0");

	std::cout << (str = "\n./convert 2147483648") << std::endl; // INT_MAX + 1
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("2147483648");

	std::cout << (str = "\n./convert 9999999999") << std::endl; // Fits long, exceeds int
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("9999999999");

	// V. Invalid / Edge Case Inputs
	std::cout << (str = "\n./convert \"\"") << std::endl; // Empty string
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("");

	std::cout << (str = "\n./convert abc") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("abc");

	std::cout << (str = "\n./convert 'a") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("'a");

	std::cout << (str = "\n./convert a'") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("a'");

	std::cout << (str = "\n./convert ''") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("''");

	std::cout << (str = "\n./convert 'ab'") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("'ab'");

	std::cout << (str = "\n./convert 1.2.3f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("1.2.3f");

	std::cout << (str = "\n./convert 1.f.2") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("1.f.2");

	std::cout << (str = "\n./convert +inffinity") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("+inffinity");

	std::cout << (str = "\n./convert 1.2.3") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("1.2.3");

	std::cout << (str = "\n./convert +infinity") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("+infinity");

	std::cout << (str = "\n./convert 42a") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("42a");

	std::cout << (str = "\n./convert 4b2") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("4b2");

	std::cout << (str = "\n./convert f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("f");

	std::cout << (str = "\n./convert .") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert(".");

	std::cout << (str = "\n./convert +") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("+");

	std::cout << (str = "\n./convert -") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("-");

	std::cout << (str = "\n./convert .f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert(".f");

	std::cout << (str = "\n./convert 1.f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("1.f");

	std::cout << (str = "\n./convert .5") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert(".5");

	std::cout << (str = "\n./convert .5f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert(".5f");

	std::cout << (str = "\n./convert 0.f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("0.f");

	// VI. Precision and Display
	std::cout << (str = "\n./convert 42.42f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("42.42f");

	std::cout << (str = "\n./convert 42.48f") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("42.48f");

	std::cout << (str = "\n./convert 42.42") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("42.42");

	std::cout << (str = "\n./convert 42.48") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;
	ScalarConverter::convert("42.48"); */
	return 0;
}
