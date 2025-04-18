/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:06:15 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/18 15:33:16 by smoore-a         ###   ########.fr       */
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
	void announce(void) const;

private:
	std::string name_;
};

Zombie *newZombie(std::string const &name);
void randomChump(std::string const &name);

#endif
