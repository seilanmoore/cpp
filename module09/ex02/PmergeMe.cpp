#include "PmergeMe.hpp"

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <ctime>

#include "mergeInsertionSort.hpp"
#include "utils.hpp"

PmergeMe::PmergeMe() : _vector(), _list()
{
}

PmergeMe::PmergeMe(const char *sequence)
{
	std::string strNumber(sequence);
	std::string token;
	size_t begin = strNumber.find_first_not_of(' ', 0);
	size_t end = 0;
	if (strNumber.empty())
		throw EmptyException();
	while (begin != std::string::npos)
	{
		end = strNumber.find(' ', begin);
		token = strNumber.substr(begin, end - begin);
		if (!token.empty())
			parseNumber(token);
		begin = strNumber.find_first_not_of(' ', end);
	}
	processAndDisplayInfo();
}

PmergeMe::PmergeMe(const char **sequence)
{
	std::string strNumber;
	for (int i = 0; sequence[i] != NULL; ++i)
	{
		std::string strNumber(sequence[i]);
		if (strNumber.find_first_not_of(' ') != std::string::npos)
			parseNumber(strNumber);
	}
	processAndDisplayInfo();
}

PmergeMe::PmergeMe(const PmergeMe &other)
	: _vector(other._vector), _list(other._list)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this == &other)
		return *this;
	_vector = other._vector;
	_list = other._list;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

size_t PmergeMe::staticPairSize = 1;
size_t PmergeMe::nComparisons = 0;

void PmergeMe::resetStatic()
{
	staticPairSize = 1;
	nComparisons = 0;
}

void PmergeMe::parseNumber(const std::string &number)
{
	std::istringstream iss(number);
	int n;
	if (!(iss >> n) || n < 0)
		throw BadNumberException(iss.str());
	_vector.push_back(n);
	_list.push_back(n);
}

void PmergeMe::validateSequence() const
{
	if (_vector.empty())
		throw EmptyException();
	if (_vector.size() == 1)
		throw FewNumbersException();
	std::vector<int> sorted(_vector);
	std::sort(sorted.begin(), sorted.end());
	std::vector<int>::iterator it;
	it = std::adjacent_find(sorted.begin(), sorted.end());
	if (it != sorted.end())
		throw DuplicateException(*it);
	if (std::equal(_vector.begin(), _vector.end(), sorted.begin()))
		throw AlreadySortedException();
}

void PmergeMe::processAndDisplayInfo()
{
	validateSequence();
	double vTime = getSortingTime<std::vector<int> >(_vector);
	double lTime = getSortingTime<std::list<int> >(_list);
	std::vector<int> sorted = _vector;
	mergeInsertionSort(sorted);
	if (!isSorted<std::vector<int> >(sorted))
		throw SortingException();
	std::cout << "Before: ";
	std::cout << printArray(_vector) << std::endl;
	std::cout << "After: ";
	std::cout << printArray(sorted) << std::endl;
	std::cout << "Time to process a range of " << _vector.size()
			  << " elements with std::vector: "
			  << std::fixed << std::setprecision(0)
			  << vTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _list.size()
			  << " elements with std::list: "
			  << std::fixed << std::setprecision(0)
			  << lTime << " us" << std::endl;
}
