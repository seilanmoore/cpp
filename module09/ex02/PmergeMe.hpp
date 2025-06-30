#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <list>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const char *number);
	PmergeMe(const char **number);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

private:
	std::vector<int> _vector;
	std::list<int> _list;

	void MIS(std::vector<int> &arr);
	void MIS(std::list<int> &arr);
	void binaryInsert(std::list<int> &sorted, int target);
	void processAndDisplayInfo();
	void validateSequence() const;
	double getSortingTime(std::vector<int> arr);
	double getSortingTime(std::list<int> arr);
	bool isSorted(const std::vector<int> &arr);
	bool isSorted(const std::list<int> &arr);
	void printVector(const std::vector<int> &v);
	void printList(const std::list<int> &l);
	void parseNumber(const std::string &number);

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
};

#endif
