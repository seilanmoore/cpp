#include "RPN.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>

RPN::RPN() : _expr(""), _stack(), _result(0)
{
}

RPN::RPN(const char *expr) : _expr(expr), _stack(), _result(0)
{
	calculateExpression();
}

RPN::RPN(const RPN &other) : _expr(other._expr), _stack(), _result(other._result)
{
}

RPN &RPN::operator=(const RPN &other)
{
	_expr = other._expr;
	_stack = std::stack<int, std::deque<int> >();
	_result = other._result;
	return *this;
}

RPN::~RPN()
{
}

void RPN::calculateExpression()
{
	size_t end = 0;
	size_t begin = 0;
	std::string token;
	size_t nToken = 0;
	if (_expr.empty() || _expr.find_first_not_of("+-*/ ") == std::string::npos)
		throw BadExpressionException();
	while ((begin = _expr.find_first_not_of(' ', begin)) != std::string::npos)
	{
		end = _expr.find(' ', begin);
		token = _expr.substr(begin, end - begin);
		// std::cout << "\'" << token << "\'" << std::endl;
		if (!token.empty())
			evaluateToken(token);
		begin = end;
		++nToken;
	}
	if (_stack.empty() ||
		(nToken != 1 && token.find_first_not_of("+-*/") != std::string::npos))
		throw BadExpressionException();
	_result = _stack.top();
	_stack = std::stack<int, std::deque<int> >();
}

void RPN::evaluateToken(const std::string &token)
{
	std::pair<int, int> operands;
	if (token.find_first_of("+-*/") != std::string::npos && _stack.size() == 1)
		throw BadExpressionException();
	if (token == "+")
	{
		operands = popOperands();
		_stack.push(operands.first + operands.second);
	}
	else if (token == "-")
	{
		operands = popOperands();
		_stack.push(operands.first - operands.second);
	}
	else if (token == "*")
	{
		operands = popOperands();
		_stack.push(operands.first * operands.second);
	}
	else if (token == "/")
	{
		operands = popOperands();
		if (operands.second == 0)
			throw DivisionByZeroException();
		_stack.push(operands.first / operands.second);
	}
	else
	{
		std::istringstream iss(token);
		int operand;
		if (token.find('.') != std::string::npos || !(iss >> operand) ||
			operand < 0 || operand > 9)
			throw BadExpressionException();
		_stack.push(operand);
	}
}

std::pair<int, int> RPN::popOperands()
{
	std::pair<int, int> result;
	if (!_stack.empty())
	{
		result.second = _stack.top();
		_stack.pop();
		result.first = _stack.top();
		_stack.pop();
	}
	return result;
}

int RPN::getResult() const { return _result; }

const char *RPN::BadExpressionException::what() const throw()
{
	return "Error: bad expression";
}

const char *RPN::DivisionByZeroException::what() const throw()
{
	return "Error: division by 0";
}

std::ostream &operator<<(std::ostream &os, const RPN &obj)
{
	os << obj.getResult();
	return os;
}
