/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:48:25 by smoore-a          #+#    #+#             */
/*   Updated: 2025/06/19 20:54:06 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <cerrno>
#include <cmath>
#include <limits>
#include <iomanip>
#include <cctype>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::printAllImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::displayChar(double value)
{
	if (std::isnan(value) || std::isinf(value) ||
		value < static_cast<double>(std::numeric_limits<unsigned char>::min()) ||
		value > static_cast<double>(std::numeric_limits<unsigned char>::max()))
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	char c = static_cast<char>(value);
	if (std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::displayInt(double value)
{
	if (std::isnan(value) || std::isinf(value) ||
		value < static_cast<double>(std::numeric_limits<int>::min()) ||
		value > static_cast<double>(std::numeric_limits<int>::max()))
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::displayFloat(double value)
{
	float floatValue = static_cast<float>(value);
	if (std::isnan(floatValue))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(floatValue))
	{
		if (floatValue > 0)
			std::cout << "float: inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}
	else
	{
		std::cout << "float: "
				  << std::fixed << std::setprecision(1)
				  << floatValue << "f" << std::endl;
	}
}

void ScalarConverter::displayDouble(double value)
{
	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "double: inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
	else
	{
		std::cout << "double: "
				  << std::fixed << std::setprecision(1)
				  << value << std::endl;
	}
}

void ScalarConverter::convertFromChar(char c)
{
	if (std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	displayInt(static_cast<double>(c));
	displayFloat(static_cast<double>(c));
	displayDouble(static_cast<double>(c));
}

void ScalarConverter::convertFromInt(int i)
{
	displayChar(static_cast<double>(i));
	std::cout << "int: " << static_cast<int>(i) << std::endl;
	displayFloat(static_cast<double>(i));
	displayDouble(static_cast<double>(i));
}

void ScalarConverter::convertFromFloat(float f)
{
	displayChar(static_cast<double>(f));
	displayInt(static_cast<double>(f));
	if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(f) && f > 0)
		std::cout << "float: inff" << std::endl;
	else if (std::isinf(f) && f < 0)
		std::cout << "float: -inff" << std::endl;
	else
	{
		std::cout << "float: "
				  << std::fixed << std::setprecision(1)
				  << f << "f" << std::endl;
	}
	displayDouble(static_cast<double>(f));
}

void ScalarConverter::convertFromDouble(double d)
{
	displayChar(d);
	displayInt(d);
	displayFloat(d);
	displayDouble(d);
}

bool ScalarConverter::isEmpty(const std::string &literal)
{
	if (literal.empty())
	{
		printAllImpossible();
		return true;
	}
	return false;
}

bool ScalarConverter::isChar(const std::string &literal)
{
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
	{
		convertFromChar(static_cast<char>(literal[1]));
		return true;
	}
	return false;
}

bool ScalarConverter::isPseudoLiteral(const std::string &literal)
{
	if (literal == "nanf")
	{
		convertFromFloat(std::numeric_limits<float>::quiet_NaN());
		return true;
	}
	if (literal == "inff")
	{
		convertFromFloat(std::numeric_limits<float>::infinity());
		return true;
	}
	if (literal == "+inff")
	{
		convertFromFloat(std::numeric_limits<float>::infinity());
		return true;
	}
	if (literal == "-inff")
	{
		convertFromFloat(-std::numeric_limits<float>::infinity());
		return true;
	}
	if (literal == "nan")
	{
		convertFromDouble(std::numeric_limits<double>::quiet_NaN());
		return true;
	}
	if (literal == "inf")
	{
		convertFromDouble(std::numeric_limits<double>::infinity());
		return true;
	}
	if (literal == "+inf")
	{
		convertFromDouble(std::numeric_limits<double>::infinity());
		return true;
	}
	if (literal == "-inf")
	{
		convertFromDouble(-std::numeric_limits<double>::infinity());
		return true;
	}
	return false;
}

bool ScalarConverter::isString(const std::string &literal)
{
	std::stringstream ss(literal);
	long double value;
	if (!(ss >> value))
	{
		printAllImpossible();
		return true;
	}
	return false;
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	std::stringstream ss(literal);
	double doubleValue;
	if (literal[literal.length() - 1] == 'f' && ss >> doubleValue)
	{
		convertFromFloat(static_cast<float>(doubleValue));
		return true;
	}
	return false;
}

bool ScalarConverter::isInt(const std::string &literal)
{
	for (size_t i = 0; i < literal.length(); ++i)
	{
		if (literal[i] == '.' || literal[i] == 'e' || literal[i] == 'E')
			return false;
	}
	std::stringstream ss(literal);
	long longValue;
	if (ss >> longValue && longValue >= static_cast<long>(std::numeric_limits<int>::min()) &&
		longValue <= static_cast<long>(std::numeric_limits<int>::max()))
	{
		convertFromInt(static_cast<int>(longValue));
		return true;
	}
	return false;
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	std::stringstream ss(literal);
	long double value;
	if (ss >> value)
	{
		convertFromDouble(static_cast<double>(value));
		return true;
	}
	return false;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (isEmpty(literal))
		return;
	if (isChar(literal))
		return;
	if (isPseudoLiteral(literal))
		return;
	if (isString(literal))
		return;
	if (isFloat(literal))
		return;
	if (isInt(literal))
		return;
	if (isDouble(literal))
		return;
	printAllImpossible();
}
