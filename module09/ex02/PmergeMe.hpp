#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "mergeInsertionSort.hpp"
#include "exceptions.hpp"
#include "utils.hpp"

#include <iostream>
#include <vector>
#include <list>

#define USAGE "Usage: ./PmergeMe [Number]... or \"[Number]...\"\n"

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const char *sequence);
	PmergeMe(const char **sequence);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	static size_t nComparisons;
	static size_t staticPairSize;

private:
	std::vector<int> _vector;
	std::list<int> _list;

	void processAndDisplayInfo();
	void validateSequence() const;
	void parseNumber(const std::string &number);

	template <typename T>
	double getSortingTime(T arr);

	static void resetStatic();
};

template <typename T>
double PmergeMe::getSortingTime(T arr)
{
	clock_t start = clock();
	mergeInsertionSort(arr);
	clock_t end = clock();
	// std::cout << "nComparisons: " << PmergeMe::nComparisons << std::endl;
	PmergeMe::resetStatic();
	if (!isSorted<T>(arr))
		throw SortingException();
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6;
}

#endif
