/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:10:43 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/20 11:35:18 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int argc, char **argv)
{
	Replacer replace(argv[1], argv[2], argv[3]);

	if (argc != 4)
		return printError(USE, "");
	replace.seekReplace();
	tests();
	return 0;
}
