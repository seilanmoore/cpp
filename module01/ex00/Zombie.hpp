/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:06:15 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/18 13:28:50 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
public:
	Zombie(void) : name_("Paco") {};
	Zombie(std::string const &name) : name_(name) {};
	~Zombie(void);
	void announce(void);

private:
	std::string name_;
};

Zombie *newZombie(std::string const &name);
void randomChump(std::string const &name);
