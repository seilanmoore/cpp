#ifndef PAIR_HPP
#define PAIR_HPP

#include <cstddef>

template <typename T>
class Pair
{
public:
	Pair();
	Pair(const T &elements, char type, size_t numType);
	Pair(const Pair &other);
	Pair &operator=(const Pair &other);
	~Pair();

	const T &getElements() const;
	char getType() const;
	size_t getNumType() const;
	int getKey() const;

private:
	T _elements;
	char _type;
	size_t _numType;
};

template <typename T>
Pair<T>::Pair() : _elements(), _type('a'), _numType(1)
{
}

template <typename T>
Pair<T>::Pair(const T &elements, char type, size_t numType)
	: _elements(elements), _type(type), _numType(numType)
{
}

template <typename T>
Pair<T>::Pair(const Pair &other)
	: _elements(other._elements), _type(other._type), _numType(other._numType)
{
}

template <typename T>
Pair<T> &Pair<T>::operator=(const Pair &other)
{
	if (this == &other)
		return *this;
	_elements = other._elements;
	_type = other._type;
	_numType = other._numType;
	return *this;
}

template <typename T>
Pair<T>::~Pair()
{
}

template <typename T>
const T &Pair<T>::getElements() const
{
	return _elements;
}

template <typename T>
char Pair<T>::getType() const
{
	return _type;
}

template <typename T>
size_t Pair<T>::getNumType() const
{
	return _numType;
}

template <typename T>
int Pair<T>::getKey() const
{
	return _elements.back();
}

#endif
