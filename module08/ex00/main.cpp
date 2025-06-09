/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:23:21 by smoore-a          #+#    #+#             */
/*   Updated: 2025/06/09 17:53:00 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>

#include "easyfind.hpp"

// class num
// {
// public:
// 	num() : _n(0) {};
// 	num(int n) : _n(n) {};
// 	num(const num &other) : _n(other._n) {};
// 	num &operator=(const num &other)
// 	{
// 		_n = other._n;
// 		return *this;
// 	}
// 	bool operator!=(const num &other) const
// 	{
// 		return _n != other._n;
// 	}
// 	bool operator==(const int value) const
// 	{
// 		return _n == value;
// 	}
// 	~num() {};

// 	int _n;
// };

// std::ostream &operator<<(std::ostream &os, const num &n)
// {
// 	os << n._n;
// 	return os;
// }

int main()
{
	std::string str;
	std::cout << (str = "TEST VECTOR") << std::endl;
	std::cout << std::setw(str.length()) << std::setfill('-') << "" << std::endl;

	std::vector<int> v(5);
	v.at(0) = 0;
	v.at(1) = 10;
	v.at(2) = 20;
	v.at(3) = 30;
	v.at(4) = 40;

	std::vector<int>::iterator it = easyfind(v, 40);
	if (it != v.end())
		std::cout << "The number " << *it << " was found" << std::endl;
	else
		std::cout << "Number not found" << std::endl;
	/////////////////////////////////////////////////////////////////////////////////
	// std::cout << (str = "\nTEST VECTOR COMPLEX TYPE") << std::endl;
	// std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;

	// std::vector<num> n(5);
	// n[0] = 0;
	// n[1] = 10;
	// n[2] = 20;
	// n[3] = 30;
	// n[4] = 40;
	// std::vector<num>::iterator numIt;

	// numIt = easyfind(n, 20);
	// if (numIt != n.end())
	// std::cout << "The number " << *numIt << " was found" << std::endl;
	// else
	// std::cout << "Number not found" << std::endl;
	// numIt = easyfind(n, 5);
	// if (numIt != n.end())
	// std::cout << "\nThe number " << *numIt << " was found" << std::endl;
	// else
	// std::cout << "\nNumber not found" << std::endl;
	/////////////////////////////////////////////////////////////////////////////////
	std::cout << (str = "\nTEST LIST") << std::endl;
	std::cout << std::setw(str.length() - 1) << std::setfill('-') << "" << std::endl;

	int intArray[] = {0, 10, 20, 30, 40};
	std::list<int> lst(intArray, intArray + 5);
	std::list<int>::iterator lstIt = easyfind(lst, 10);

	if (lstIt != lst.end())
		std::cout << "The number " << *lstIt << " was found" << std::endl;
	else
		std::cout << "Number not found" << std::endl;
	*lstIt = 5;
	lst.pop_front();
	std::cout << "Second node value now is " << lst.front() << std::endl;
	return 0;
}
