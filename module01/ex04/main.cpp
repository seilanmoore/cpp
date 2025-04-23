/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:10:43 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/23 12:38:50 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int argc, char **argv)
{
	Replacer *replace;

	if (argc != 4)
		return printError(USE, "");
	replace = new Replacer(argv[1], argv[2], argv[3]);
	if (replace->seekReplace())
	{
		delete replace;
		return 1;
	}
	delete replace;
	// tests();
	return 0;
}
