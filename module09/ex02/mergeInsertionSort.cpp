#include "mergeInsertionSort.hpp"

#include <cmath>

#include "PmergeMe.hpp"
#include "Pair.hpp"

long getJacobsthal(long n)
{
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

std::list<int>::iterator next(std::list<int>::iterator it, size_t n)
{
	std::advance(it, n);
	return it;
}

tLPairList::iterator next(tLPairList::iterator it, size_t n)
{
	std::advance(it, n);
	return it;
}

size_t binarySearch(const tLPairList &main, size_t endPos, int target)
{
	size_t left = 0;
	size_t right = endPos;

	while (left < right)
	{
		size_t middle = left + static_cast<size_t>(std::floor((right - left) / 2));
		tLPairList::const_iterator middleIt = main.begin();
		std::advance(middleIt, middle);
		if (middleIt->getKey() < target)
			left = middle + 1;
		else
			right = middle;
		++PmergeMe::nComparisons;
	}
	return left;
}

size_t binarySearch(const tVPairVector &mainStart, size_t endPos, int target)
{
	size_t left = 0;
	size_t right = endPos;
	while (left < right)
	{
		size_t middle = left + static_cast<size_t>(std::floor((right - left) / 2));
		if (mainStart[middle].getKey() < target)
			left = middle + 1;
		else
			right = middle;
		++PmergeMe::nComparisons;
	}
	return left;
}

size_t findBound(const tLPairList &main, const tLPair &element)
{
	tLPairList::const_reverse_iterator rit = main.rbegin();
	size_t index = main.size() - 1;

	for (; rit != main.rend(); ++rit, --index)
	{
		if (rit->getNumType() == element.getNumType())
			return index;
	}
	return main.size();
}

size_t findBound(const tVPairVector &main, const tVPair &element)
{
	for (size_t i = main.size(); i > 0; --i)
	{
		if (main[i - 1].getNumType() == element.getNumType())
			return i - 1;
	}
	return main.size();
}

void mergeInsertionSort(std::list<int> &arr)
{
	size_t pairSize = PmergeMe::staticPairSize;
	size_t n = arr.size();
	if ((pairSize * 2) > n)
		return;

	typedef std::list<int>::iterator tIterator;

	for (size_t i = 0; i + (pairSize * 2) <= n; i += (pairSize * 2))
	{
		size_t j = i + (pairSize - 1);
		tIterator small = next(arr.begin(), i);

		tIterator bKey = next(arr.begin(), j);
		int b = *bKey;

		tIterator aKey = next(arr.begin(), j + pairSize);
		int a = *aKey;

		if (a < b)
		{
			tIterator large = next(arr.begin(), i + pairSize);
			std::swap_ranges(small, large, large);
		}
		++PmergeMe::nComparisons;
	}

	PmergeMe::staticPairSize *= 2;
	mergeInsertionSort(arr);

	double nPair = static_cast<double>(n) / (static_cast<double>(pairSize) * 2.0);
	size_t nPairA = static_cast<size_t>(std::floor(nPair));
	size_t nPairB = static_cast<size_t>(round(nPair));

	tLPairList main;
	tLPairList pend;

	std::list<int>::iterator endIt = next(arr.begin(), pairSize);

	std::list<int> elements(arr.begin(), endIt);
	tLPair pair(elements, 'b', 1);
	main.push_back(pair);
	for (size_t i = 0; i < nPairA; ++i)
	{
		size_t start = pairSize + (pairSize * 2 * i);
		std::list<int>::iterator startIt = next(arr.begin(), start);
		std::list<int>::iterator endIt = next(startIt, pairSize);
		std::list<int> elements(startIt, endIt);
		tLPair pair(elements, 'a', i + 1);
		main.push_back(pair);
	}
	for (size_t i = 1; i < nPairB; ++i)
	{
		size_t start = pairSize * 2 * i;
		std::list<int>::iterator startIt = next(arr.begin(), start);
		std::list<int>::iterator endIt = next(startIt, pairSize);
		std::list<int> elements(startIt, endIt);
		tLPair pair(elements, 'b', i + 1);
		pend.push_back(pair);
	}

	int prevPendIdx = -1;
	size_t pendSize = pend.size();
	for (size_t k = 2;; ++k)
	{
		size_t jacobNum = getJacobsthal(k);
		size_t pendIdx = jacobNum - 2;

		if (pendIdx >= pendSize)
			pendIdx = pendSize - 1;
		for (int j = static_cast<int>(pendIdx); j > prevPendIdx; --j)
		{
			tLPairList::iterator pendIt = next(pend.begin(), j);

			size_t bound;
			if (nPairA >= pendIt->getNumType())
				bound = findBound(main, *pendIt);
			else
				bound = main.size();

			size_t pos = binarySearch(main, bound, pendIt->getKey());

			tLPairList::iterator mainIt = next(main.begin(), pos);
			main.insert(mainIt, *pendIt);
		}
		if (pendIdx + 1 >= pendSize)
			break;
		prevPendIdx = pendIdx;
	}

	std::list<int> arrCopy;
	tLPairList::const_iterator mainIt;
	for (mainIt = main.begin(); mainIt != main.end(); ++mainIt)
	{
		std::list<int>::const_iterator start = mainIt->getElements().begin();
		std::list<int>::const_iterator end = mainIt->getElements().end();
		arrCopy.insert(arrCopy.end(), start, end);
	}
	if (n % pairSize)
	{
		std::list<int>::iterator start;
		start = next(arr.begin(), n - (n % pairSize));
		arrCopy.insert(arrCopy.end(), start, arr.end());
	}
	arr = arrCopy;
}

void mergeInsertionSort(std::vector<int> &arr)
{
	size_t pairSize = PmergeMe::staticPairSize;
	size_t n = arr.size();

	if ((pairSize * 2) > n)
		return;

	for (size_t i = 0; i + (pairSize * 2) <= n; i += (pairSize * 2))
	{
		size_t j = i + (pairSize - 1);
		int b = arr[j];
		int a = arr[j + pairSize];
		if (a < b)
			std::swap_ranges(&(arr[i]), &(arr[i + pairSize]), &(arr[i + pairSize]));
		++PmergeMe::nComparisons;
	}

	PmergeMe::staticPairSize *= 2;
	mergeInsertionSort(arr);

	double nPair = static_cast<double>(n) / (static_cast<double>(pairSize) * 2.0);
	size_t nPairA = static_cast<size_t>(std::floor(nPair));
	size_t nPairB = static_cast<size_t>(round(nPair));

	tVPairVector main;
	tVPairVector pend;

	std::vector<int>::const_iterator vIt = arr.begin();
	std::vector<int> elements(vIt, vIt + pairSize);
	tVPair pair(elements, 'b', 1);
	main.push_back(pair);
	for (size_t i = 0; i < nPairA; ++i)
	{
		size_t start = pairSize + (pairSize * 2 * i);
		std::vector<int>::const_iterator it = arr.begin() + start;
		std::vector<int> elements(it, it + pairSize);
		tVPair pair(elements, 'a', i + 1);
		main.push_back(pair);
	}
	for (size_t i = 1; i < nPairB; ++i)
	{
		size_t start = pairSize * 2 * i;
		std::vector<int>::const_iterator it = arr.begin() + start;
		std::vector<int> elements(it, it + pairSize);
		tVPair pair(elements, 'b', i + 1);
		pend.push_back(pair);
	}

	int prevPendIdx = -1;
	size_t pendSize = pend.size();
	for (size_t k = 2;; ++k)
	{
		size_t jacobNum = getJacobsthal(k);
		size_t pendIdx = jacobNum - 2;

		if (pendIdx >= pendSize)
			pendIdx = pendSize - 1;
		for (int j = static_cast<int>(pendIdx); j > prevPendIdx; --j)
		{
			size_t bound;
			if (nPairA >= pend[j].getNumType())
				bound = findBound(main, pend[j]);
			else
				bound = main.size();
			size_t pos = binarySearch(main, bound, pend[j].getKey());
			main.insert(main.begin() + pos, pend[j]);
		}
		if (pendIdx + 1 >= pendSize)
			break;
		prevPendIdx = pendIdx;
	}

	std::vector<int> arrCopy;
	for (size_t i = 0; i < main.size(); ++i)
	{
		std::vector<int>::const_iterator start = main[i].getElements().begin();
		std::vector<int>::const_iterator end = main[i].getElements().end();
		arrCopy.insert(arrCopy.end(), start, end);
	}
	if (n % pairSize)
		arrCopy.insert(arrCopy.end(), arr.end() - (n % pairSize), arr.end());
	arr = arrCopy;
}
