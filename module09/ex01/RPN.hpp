#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <deque>
#include <string>
#include <fstream>
#include <exception>

class RPN
{
public:
	RPN();
	RPN(const char *expr);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	int getResult() const;

	void calculateExpression();
	void evaluateToken(const std::string &token);
	std::pair<int, int> popOperands();

	class BadExpressionException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class DivisionByZeroException : public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	std::string _expr;
	std::stack<int, std::deque<int> > _stack;
	int _result;
};

std::ostream &operator<<(std::ostream &os, const RPN &obj);

#endif
