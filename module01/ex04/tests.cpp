/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:34:32 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/20 11:40:17 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

void tests(void)
{
	{
		std::string file = "tests/letter.txt";
		std::string s1 = "a";
		std::string s2 = "pa";
		Replacer replace(file, s1, s2);
		replace.seekReplace();
	}
	{
		std::string file = "tests/cat.txt";
		std::string s1 = "cat";
		std::string s2 = "dog";
		Replacer replace(file, s1, s2);
		replace.seekReplace();
	}
	{
		std::string file = "tests/remove_x.txt";
		std::string s1 = "x";
		std::string s2 = "";
		Replacer replace(file, s1, s2);
		replace.seekReplace();
	}
	{
		std::string file = "";
		std::string s1 = "a";
		std::string s2 = "b";
		Replacer replace(file, s1, s2);
		replace.seekReplace();
	}
	{
		std::string file = "tests/empty.txt";
		std::string s1 = "a";
		std::string s2 = "b";
		Replacer replace(file, s1, s2);
		replace.seekReplace();
	}
	{
		std::string file = "tests/no_file.txt";
		std::string s1 = "a";
		std::string s2 = "b";
		Replacer replace(file, s1, s2);
		replace.seekReplace();
	}
	{
		std::string file = "tests/error.txt";
		std::string s1 = "";
		std::string s2 = "b";
		Replacer replace(file, s1, s2);
		replace.seekReplace();
	}
	{
		std::string file = "tests/error.txt";
		std::string s1 = "a";
		std::string s2 = "a";
		Replacer replace(file, s1, s2);
		replace.seekReplace();
	}
}
