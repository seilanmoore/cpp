#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>
#include <exception>

class BadNumberException : public std::exception
{
public:
	BadNumberException(const std::string &msg);
	virtual ~BadNumberException() throw();

	const char *what() const throw();

private:
	std::string _msg;
};

class DuplicateException : public std::exception
{
public:
	DuplicateException(int number);
	virtual ~DuplicateException() throw();

	const char *what() const throw();

private:
	std::string _msg;
};

class EmptyException : public std::exception
{
public:
	const char *what() const throw();
};

class FewNumbersException : public std::exception
{
public:
	const char *what() const throw();
};

class AlreadySortedException : public std::exception
{
public:
	const char *what() const throw();
};

class SortingException : public std::exception
{
public:
	const char *what() const throw();
};

#endif
