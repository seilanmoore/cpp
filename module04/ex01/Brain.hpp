/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:20:54 by smoore-a          #+#    #+#             */
/*   Updated: 2025/05/08 21:31:42 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
public:
	Brain(void);
	Brain(const std::string &idea);
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain(void);

	const std::string *getIdeas(void) const;

private:
	std::string _ideas[100];
};

#endif
