#include "PmergeMe.hpp"

#include <iostream>
#include <stack>
#include <deque>
#include <sstream>
#include <exception>

int main(int argc, const char **argv)
{
	if (argc < 2)
		return (std::cerr << "Usage: ./PmergeMe [Number]... or \"[Number]...\"\n", 1);
	if (argc == 2)
	{
		try
		{
			PmergeMe pmm(argv[1]);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
	{
		try
		{
			PmergeMe pmm(&(argv[1]));
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}
