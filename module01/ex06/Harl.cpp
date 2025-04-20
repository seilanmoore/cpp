/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:53:06 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/20 20:06:17 by smoore-a         ###   ########.fr       */
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
	if (levelType == "DEBUG")
		return 0;
	else if (levelType == "INFO")
		return 1;
	else if (levelType == "WARNING")
		return 2;
	else if (levelType == "ERROR")
		return 3;
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
		break;
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
