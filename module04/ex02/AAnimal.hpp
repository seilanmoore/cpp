/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:20:54 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/08 22:37:40 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ANIMAL_HPP
#define A_ANIMAL_HPP

#include <iostream>

class AAnimal
{
public:
	AAnimal(void);
	AAnimal(const std::string &type);
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &other);
	virtual ~AAnimal(void);

	const std::string &getType(void) const;

	virtual void makeSound(void) const = 0;

protected:
	std::string _type;
};

#endif
