/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:53:06 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/20 20:13:16 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void Harl::complain(const std::string &levelType)
{
	levelHandler level[] = {
		{"DEBUG", &Harl::_debug},
		{"INFO", &Harl::_info},
		{"WARNING", &Harl::_warning},
		{"ERROR", &Harl::_error}};

	for (int i = 0; i < 4; ++i)
	{
		if (level[i].type == levelType)
		{
			(this->*level[i].func)();
			break;
		}
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
