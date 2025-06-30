#include "RPN.hpp"

#include <iostream>
#include <stack>
#include <deque>
#include <sstream>
#include <exception>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Usage: ./rpn \"reverse polish mathematical expr\"\n", 1);
	try
	{
		RPN rpn(argv[1]);
		std::cout << rpn << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	return 0;
}
