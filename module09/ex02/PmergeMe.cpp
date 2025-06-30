#include "PmergeMe.hpp"

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctime>

PmergeMe::PmergeMe() : _vector(), _list()
{
}

PmergeMe::PmergeMe(const char *number)
{
	std::string strNumber(number);
	std::string token;
	size_t begin = 0;
	size_t end = 0;
	if (strNumber.empty())
		throw EmptyException();
	while ((begin = strNumber.find_first_not_of(' ', begin)) != std::string::npos)
	{
		end = strNumber.find(' ', begin);
		token = strNumber.substr(begin, end - begin);
		if (!token.empty())
			parseNumber(token);
		begin = end;
	}
	processAndDisplayInfo();
}

PmergeMe::PmergeMe(const char **number)
{
	std::string strNumber;
	for (int i = 0; number[i] != NULL; ++i)
	{
		std::string strNumber(number[i]);
		parseNumber(strNumber);
	}
	processAndDisplayInfo();
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this == &other)
		return *this;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::MIS(std::vector<int> &arr)
{
	size_t n = arr.size();
	if (n <= 1)
		return;
	std::vector<int> greaterElements;
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < n; i += 2)
	{
		int a = arr[i];
		int b = arr[i + 1];
		if (a > b)
		{
			greaterElements.push_back(a);
			pairs.push_back(std::make_pair(a, b));
		}
		else
		{
			greaterElements.push_back(b);
			pairs.push_back(std::make_pair(b, a));
		}
	}
	if (n % 2)
		greaterElements.push_back(arr.back());
	MIS(greaterElements);
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		int target = pairs[i].second;
		std::vector<int>::iterator it =
			std::lower_bound(greaterElements.begin(), greaterElements.end(), target);
		greaterElements.insert(it, target);
	}
	arr = greaterElements;
}

void PmergeMe::MIS(std::list<int> &arr)
{
	size_t n = arr.size();
	if (n <= 1)
		return;
	std::list<int> greaterElements;
	std::list<std::pair<int, int> > pairs;
	std::list<int>::const_iterator it;
	for (it = arr.begin(); it != arr.end(); std::advance(it, 2))
	{
		std::list<int>::const_iterator tmp = it;
		if (++tmp == arr.end())
			break;
		int a = *it;
		int b = *tmp;
		if (a > b)
		{
			greaterElements.push_back(a);
			pairs.push_back(std::make_pair(a, b));
		}
		else
		{
			greaterElements.push_back(b);
			pairs.push_back(std::make_pair(b, a));
		}
	}
	if (n % 2)
		greaterElements.push_back(arr.back());
	MIS(greaterElements);
	std::list<std::pair<int, int> >::const_iterator pairsIt;
	for (pairsIt = pairs.begin(); pairsIt != pairs.end(); ++pairsIt)
		binaryInsert(greaterElements, (*pairsIt).second);
	arr = greaterElements;
}

void PmergeMe::binaryInsert(std::list<int> &sorted, int target)
{
	size_t left = 0;
	size_t right = sorted.size();
	std::list<int>::iterator it;
	while (left < right)
	{
		it = sorted.begin();
		size_t middle = left + std::floor((right - left) / 2);
		std::advance(it, middle);
		if (*it < target)
			left = middle + 1;
		else
			right = middle;
	}
	it = sorted.begin();
	std::advance(it, left);
	sorted.insert(it, target);
}

void PmergeMe::processAndDisplayInfo()
{
	validateSequence();
	double vTime = getSortingTime(_vector);
	double lTime = getSortingTime(_list);
	std::vector<int> sorted = _vector;
	MIS(sorted);
	std::cout << "Before: ";
	printVector(_vector);
	std::cout << "After: ";
	printVector(sorted);
	std::cout << "Time to process a range of " << _vector.size()
			  << " elements with std::vector: " << std::fixed << std::setprecision(6)
			  << vTime << " s" << std::endl;
	std::cout << "Time to process a range of " << _list.size()
			  << " elements with std::list: " << std::fixed << std::setprecision(6)
			  << lTime << " s" << std::endl;
}

void PmergeMe::validateSequence() const
{
	if (_vector.size() == 1)
		throw FewNumbersException();
	std::vector<int> sorted(_vector);
	std::sort(sorted.begin(), sorted.end());
	std::vector<int>::iterator it = std::adjacent_find(sorted.begin(), sorted.end());
	if (it != sorted.end())
		throw DuplicateException(*it);
	if (std::equal(_vector.begin(), _vector.end(), sorted.begin()))
		throw AlreadySortedException();
}

double PmergeMe::getSortingTime(std::vector<int> arr)
{
	clock_t start = clock();
	MIS(arr);
	clock_t end = clock();
	// printVector(arr);
	if (!isSorted(arr))
		throw SortingException();
	return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

double PmergeMe::getSortingTime(std::list<int> arr)
{
	clock_t start = clock();
	MIS(arr);
	clock_t end = clock();
	// printList(arr);
	if (!isSorted(arr))
		throw SortingException();
	return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

bool PmergeMe::isSorted(const std::vector<int> &arr)
{
	std::vector<int> sorted(arr);
	std::sort(sorted.begin(), sorted.end());
	return std::equal(arr.begin(), arr.end(), sorted.begin());
}

bool PmergeMe::isSorted(const std::list<int> &arr)
{
	std::list<int> sorted(arr);
	sorted.sort();
	return std::equal(arr.begin(), arr.end(), sorted.begin());
}

void PmergeMe::printVector(const std::vector<int> &v)
{
	std::vector<int>::const_iterator vIt;
	for (vIt = v.begin(); vIt != v.end(); ++vIt)
		std::cout << *vIt << " ";
	std::cout << std::endl;
}

void PmergeMe::printList(const std::list<int> &l)
{
	std::list<int>::const_iterator it;
	for (it = l.begin(); it != l.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
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

PmergeMe::BadNumberException::BadNumberException(const std::string &msg)
	: _msg("Error: bad number: " + msg)
{
}

PmergeMe::BadNumberException::~BadNumberException() throw()
{
}

const char *PmergeMe::BadNumberException::what() const throw()
{
	return _msg.c_str();
}

PmergeMe::DuplicateException::DuplicateException(int number)
	: _msg("Error: duplicated number")
{
	std::ostringstream oss;
	if (oss << number)
		_msg += ": " + oss.str();
}

PmergeMe::DuplicateException::~DuplicateException() throw()
{
}

const char *PmergeMe::DuplicateException::what() const throw()
{
	return _msg.c_str();
}

const char *PmergeMe::EmptyException::what() const throw()
{
	return "Error: empty sequence";
}

const char *PmergeMe::FewNumbersException::what() const throw()
{
	return "Error: few numbers to sort";
}

const char *PmergeMe::AlreadySortedException::what() const throw()
{
	return "Error: sequence is already sorted";
}

const char *PmergeMe::SortingException::what() const throw()
{
	return "Error: sequence was not sorted correctly";
}
