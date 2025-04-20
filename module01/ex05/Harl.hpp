/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:53:18 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/20 20:12:34 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <iostream>

class Harl
{
public:
	Harl(void);
	~Harl(void);
	void complain(const std::string &level);

private:
	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);
};

typedef struct levelHandler
{
	std::string type;
	void (Harl::*func)(void);
} s_levelHandler;

#endif
