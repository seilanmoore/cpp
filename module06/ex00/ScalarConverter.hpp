/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:07:52 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/23 06:39:22 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
public:
	static void convert(const std::string &literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static void printAllImpossible();

	static void displayChar(double value);
	static void displayInt(double value);
	static void displayFloat(double value);
	static void displayDouble(double value);

	static void convertFromChar(char c);
	static void convertFromInt(int i);
	static void convertFromFloat(float f);
	static void convertFromDouble(double d);

	static bool isEmpty(const std::string &literal);
	static bool isChar(const std::string &literal);
	static bool isPseudoLiteral(const std::string &literal);
	static bool isString(const std::string &literal);
	static bool isFloat(const std::string &literal);
	static bool isInt(const std::string &literal);
	static bool isDouble(const std::string &literal);
};

#endif
