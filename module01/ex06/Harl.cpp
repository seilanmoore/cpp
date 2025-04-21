/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:53:06 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/21 17:21:32 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

static int getLevel(const std::string &levelType)
{
	const std::string level[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level[i] == levelType)
			return i;
	}
	return -1;
}

void Harl::complain(const std::string &levelType)
{
	switch (getLevel(levelType))
	{
	case 0:
		this->_debug();
		// fall through
	case 1:
		this->_info();
		// fall through
	case 2:
		this->_warning();
		// fall through
	case 3:
		this->_error();
		break;
	default:
		std::cout << "Default message" << std::endl;
	}
}

void Harl::_debug(void)
{
	std::cout << "[DEBUG]" << std::endl
			  << "Debug message" << std::endl;
}

void Harl::_info(void)
{
	std::cout << "[INFO]" << std::endl
			  << "Info message" << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "[WARNING]" << std::endl
			  << "Warning message" << std::endl;
}

void Harl::_error(void)
{
	std::cout << "[ERROR]" << std::endl
			  << "Error message" << std::endl;
}
