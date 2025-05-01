/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:15:45 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/01 07:59:40 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
}

Fixed::Fixed(const int value) : _value(value << _fractBits)
{
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractBits)))
{
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_value = other._value;
	return *this;
}

Fixed::~Fixed(void)
{
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << _fractBits);
}

int Fixed::toInt(void) const
{
	return _value >> _fractBits;
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(const int raw)
{
	_value = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

bool Fixed::operator>(const Fixed &other) const
{
	return _value > other._value;
}

bool Fixed::operator<(const Fixed &other) const
{
	return _value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return _value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return _value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return _value != other._value;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;

	result._value = _value + other._value;
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;

	result._value = _value - other._value;
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;

	result._value = (_value * other._value) >> _fractBits;
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;

	if (other._value == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed();
	}
	result._value = (_value << _fractBits) / other._value;
	return result;
}

Fixed &Fixed::operator++(void)
{
	_value += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);

	++(*this);
	return temp;
}

Fixed &Fixed::operator--(void)
{
	_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	--(*this);
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

const int Fixed::_fractBits = 8;
