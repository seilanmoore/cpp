/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:38:50 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/11 17:54:24 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
public:
	AMateria(std::string const &type);
	virtual ~AMateria(void);

	const std::string &getType(void) const;

	virtual AMateria *clone(void) const = 0;
	virtual void use(ICharacter &target);

protected:
	std::string _type;
	AMateria(const AMateria &other);

private:
	AMateria(void);
	AMateria &operator=(const AMateria &other);
};

#endif
