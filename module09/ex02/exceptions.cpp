#include "exceptions.hpp"

#include <sstream>

BadNumberException::BadNumberException(const std::string &msg)
	: _msg("Error: bad number: " + msg)
{
}

BadNumberException::~BadNumberException() throw()
{
}

const char *BadNumberException::what() const throw()
{
	return _msg.c_str();
}

DuplicateException::DuplicateException(int number)
	: _msg("Error: duplicated number")
{
	std::ostringstream oss;
	if (oss << number)
		_msg += ": " + oss.str();
}

DuplicateException::~DuplicateException() throw()
{
}

const char *DuplicateException::what() const throw()
{
	return _msg.c_str();
}

const char *EmptyException::what() const throw()
{
	return "Error: empty sequence";
}

const char *FewNumbersException::what() const throw()
{
	return "Error: few numbers to sort";
}

const char *AlreadySortedException::what() const throw()
{
	return "Error: sequence is already sorted";
}

const char *SortingException::what() const throw()
{
	return "Error: sequence was not sorted correctly";
}
