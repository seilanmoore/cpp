#include "RPN.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>

RPN::RPN() : _expr(""), _result(0), _stack()
{
}

RPN::RPN(const char *expr) : _expr(expr), _result(0), _stack()
{
	calculateExpression();
}

RPN::RPN(const RPN &other) : _expr(other._expr), _result(other._result), _stack()
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this == &other)
		return *this;
	_expr = other._expr;
	_result = other._result;
	_stack = std::stack<int, std::deque<int> >();
	return *this;
}

RPN::~RPN()
{
}

void RPN::calculateExpression()
{
	std::string token;
	size_t begin = 0;
	size_t end = 0;
	if (_expr.empty())
		throw BadExpressionException();
	while ((begin = _expr.find_first_not_of(' ', begin)) != std::string::npos)
	{
		end = _expr.find(' ', begin);
		token = _expr.substr(begin, end - begin);
		if (!token.empty())
			evaluateToken(token);
		begin = end;
	}
	if (_stack.size() != 1)
		throw BadExpressionException();
	_result = _stack.top();
	_stack = std::stack<int, std::deque<int> >();
}

void RPN::evaluateToken(const std::string &token)
{
	if (!isOperand(token) && !(_stack.size() > 1 && isOperator(token)))
		throw BadExpressionException();
}

bool RPN::isOperand(const std::string &token)
{
	std::istringstream iss(token);
	int operand;
	if (!(iss >> operand))
		return false;
	if (token.find('.') != std::string::npos ||
		operand < -9 || operand > 9)
		throw BadExpressionException();
	_stack.push(operand);
	return true;
}

bool RPN::isOperator(const std::string &token)
{
	std::pair<int, int> operands;
	if (token == "+")
	{
		operands = popOperands();
		_stack.push(operands.first + operands.second);
		return true;
	}
	if (token == "-")
	{
		operands = popOperands();
		_stack.push(operands.first - operands.second);
		return true;
	}
	if (token == "*")
	{
		operands = popOperands();
		_stack.push(operands.first * operands.second);
		return true;
	}
	if (token == "/")
	{
		operands = popOperands();
		if (operands.second == 0)
			throw DivisionByZeroException();
		_stack.push(operands.first / operands.second);
		return true;
	}
	return false;
}

std::pair<int, int> RPN::popOperands()
{
	std::pair<int, int> result;
	result.second = _stack.top();
	_stack.pop();
	result.first = _stack.top();
	_stack.pop();
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
