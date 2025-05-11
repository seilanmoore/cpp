/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:21:53 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/11 17:06:24 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_DOG_HPP
#define WRONG_DOG_HPP

#include <iostream>

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
public:
	WrongDog(void);
	WrongDog(const WrongDog &other);
	WrongDog &operator=(const WrongDog &other);
	~WrongDog(void);

	void makeSound(void) const;
};

#endif
