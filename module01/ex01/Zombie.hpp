/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:08:11 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/18 17:04:05 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
	Zombie(void);
	Zombie(std::string const &name);
	~Zombie(void);
	void setName(std::string const &name);
	void announce(void) const;

private:
	std::string name_;
};

Zombie *zombieHorde(const int n, std::string const &name);

#endif
