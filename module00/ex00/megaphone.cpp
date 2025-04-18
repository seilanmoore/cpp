/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:14:00 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/13 15:02:21 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	argv++;
	while (*argv)
	{
		while (**argv)
		{
			std::cout << static_cast<char>(std::toupper(**argv));
			(*argv)++;
		}
		argv++;
	}
	std::cout << std::endl;
	return 0;
}
