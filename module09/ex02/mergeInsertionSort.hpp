#ifndef MERGEINSERTIONSORT_HPP
#define MERGEINSERTIONSORT_HPP

#include <vector>
#include <list>

#include "Pair.hpp"

typedef std::list<Pair<std::list<int> > > tLPairList;
typedef Pair<std::list<int> > tLPair;

typedef std::vector<Pair<std::vector<int> > > tVPairVector;
typedef Pair<std::vector<int> > tVPair;

long getJacobsthal(long n);

std::list<int>::iterator next(std::list<int>::iterator it, size_t n);
tLPairList::iterator next(tLPairList::iterator it, size_t n);

size_t binarySearch(const tLPairList &mainStart, size_t endPos, int target);
size_t binarySearch(const tVPairVector &mainStart, size_t endPos, int target);

size_t findBound(const tLPairList &main, const tLPair &element);
size_t findBound(const tVPairVector &main, const tVPair &element);

void mergeInsertionSort(std::list<int> &arr);
void mergeInsertionSort(std::vector<int> &arr);

#endif
