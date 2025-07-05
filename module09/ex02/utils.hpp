#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include <vector>

template <typename T>
std::string printArray(const T &arr)
{
	std::ostringstream oss;
	typename T::const_iterator it;
	for (it = arr.begin(); it != arr.end(); ++it)
		oss << *it << " ";
	return oss.str();
}

template <typename T>
bool isSorted(const T &arr)
{
	T sorted(arr);
	std::sort(sorted.begin(), sorted.end());
	return std::equal(arr.begin(), arr.end(), sorted.begin());
}

template <>
inline bool isSorted<std::list<int> >(const std::list<int> &arr)
{
	std::list<int> sorted(arr);
	sorted.sort();
	return std::equal(arr.begin(), arr.end(), sorted.begin());
}

#endif
