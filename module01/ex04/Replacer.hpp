/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:54:15 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/20 11:34:24 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_H
#define REPLACE_H

#include <iostream>
#include <fstream>
#include <string>

#define USE "Usage: ./replace <filename> <s1> <s2>"
#define E_OPEN "error: could not open the file: "
#define E_EMPTY "error: empty file: "
#define E_S1_EMPTY "error: s1 can't be empty"
#define E_S1_S2 "error: s1 and s2 are the same"

class Replacer
{
public:
	Replacer(void);
	Replacer(
		const std::string &inFilename,
		const std::string &s1, const std::string &s2);
	~Replacer(void);
	int openFiles(void);
	int checks(void) const;
	int seekReplace(void);

private:
	std::string _in_filename;
	std::string _out_filename;
	std::string _str_1;
	std::string _str_2;
	std::ifstream _in_file;
	std::ofstream _out_file;
};

int printError(const std::string &msg, const std::string &arg);
void tests(void);

#endif
