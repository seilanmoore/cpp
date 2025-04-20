/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:54:27 by smoore-a          #+#    #+#             */
/*   Updated: 2025/04/20 11:31:48 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(void)
{
}

Replacer::Replacer(const std::string &inFilename,
				   const std::string &s1,
				   const std::string &s2)
	: _in_filename(inFilename),
	  _out_filename(inFilename + ".replace"),
	  _str_1(s1),
	  _str_2(s2)
{
}

Replacer::~Replacer(void)
{
	this->_in_file.close();
	this->_out_file.close();
}

int Replacer::openFiles(void)
{
	if (this->_in_filename == "")
		return printError(USE, "");
	this->_in_file.open(this->_in_filename.c_str(),
						std::ios::in | std::ios::ate);
	if (!this->_in_file.is_open())
		return printError(E_OPEN, this->_in_filename);
	if (this->_in_file.tellg() == 0)
		return printError(E_EMPTY, this->_in_filename);
	this->_in_file.seekg(0);
	this->_out_file.open(this->_out_filename.c_str(),
						 std::ios::out | std::ios::trunc);
	if (!this->_out_file.is_open())
		return printError(E_OPEN, this->_out_filename);
	return 0;
}

int Replacer::checks(void) const
{
	if (this->_str_1 == "")
		return printError(E_S1_EMPTY, "");
	if (this->_str_1 == this->_str_2)
		return printError(E_S1_S2, "");
	return 0;
}

int Replacer::seekReplace(void)
{
	std::string line;
	size_t index;

	if (checks())
		return 1;
	if (openFiles())
		return 1;
	while (this->_in_file.good())
	{
		getline(this->_in_file, line);
		index = line.find(this->_str_1);
		while (index != std::string::npos)
		{
			line.erase(index, this->_str_1.length());
			line.insert(index, this->_str_2);
			index = line.find(this->_str_1, index + this->_str_2.length());
		}
		if (!_in_file.eof())
			this->_out_file << line << std::endl;
	}
	return 0;
}

int printError(const std::string &msg, const std::string &arg)
{
	std::cerr << msg << arg << std::endl;
	return 1;
}
