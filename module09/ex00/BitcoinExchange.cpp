#include "BitcoinExchange.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <limits>

BitcoinExchange::BitcoinExchange() : iData()
{
}

BitcoinExchange::BitcoinExchange(const std::string &input) : iData()
{
	std::ifstream ifs;
	if (!openInput(ifs, input))
		return;
	std::string line;
	getline(ifs, line);
	while (getline(ifs, line))
	{
		std::istringstream iss(line);
		std::string date;
		getline(iss, date, '|');
		std::string value;
		getline(iss, value);
		parseInput(date, value);
	}
	ifs.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

static std::string formatValue(double value)
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2) << value;
	std::string valueStr(oss.str());
	valueStr.erase(valueStr.find_last_not_of('0') + 1, std::string::npos);
	if (valueStr.at(valueStr.size() - 1) == '.')
		valueStr.resize(valueStr.size() - 1);
	return valueStr;
}

void BitcoinExchange::printData() const
{
	std::map<time_t, double>::iterator it = _data.begin();
	while (it != _data.end())
	{
		char date[11];
		tm *tm = localtime(&(it->first));
		strftime(date, 11, "%Y-%m-%d", tm);
		std::cout << date << "," << formatValue(it->second) << std::endl;
		++it;
	}
}

bool BitcoinExchange::openInput(std::ifstream &ifs, const std::string &input) const
{
	ifs.open(input.c_str());
	if (!ifs.is_open())
	{
		std::cerr << "Error: could not open input file" << std::endl;
		return false;
	}
	return true;
}

static std::string trim(const std::string &str)
{
	size_t first = str.find_first_not_of(" \t\n\r\f\v");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\n\r\f\v");
	return str.substr(first, last - first + 1);
}

bool BitcoinExchange::checkInputFormat(const std::string &date, const std::string &strValue)
{
	if (strptime((date).c_str(), "%Y-%m-%d", &(iData.tm)) == NULL)
	{
		std::cerr << "Error: bad date: " << date << std::endl;
		return false;
	}
	time_t tmp = mktime(&iData.tm);
	char checkDate[11];
	tm *tm = localtime(&tmp);
	strftime(checkDate, 11, "%Y-%m-%d", tm);
	std::string strDate(checkDate);
	if (strDate != trim(date))
	{
		std::cerr << "Error: bad date: " << date << std::endl;
		return false;
	}
	if (strValue == "")
	{
		std::cerr << "Error: bad input: empty value => " << date << std::endl;
		return false;
	}
	std::istringstream iss(strValue);
	if (!(iss >> iData.value) || iData.value == 0e0)
	{
		std::cerr << "Error: bad value: " << strValue << " => "
				  << date << std::endl;
		return false;
	}
	return true;
}

double BitcoinExchange::exchangeValue() const
{
	tm tm = iData.tm;
	time_t time = mktime(&tm);
	std::map<time_t, double>::iterator it = _data.lower_bound(time);
	if (it->first != time)
		--it;
	return it->second * iData.value;
}

void BitcoinExchange::checkInputValue()
{
	double value = iData.value;
	char fmtDate[11];
	strftime(fmtDate, 11, "%Y-%m-%d", &(iData.tm));
	if (value < 0e0)
	{
		std::cerr << "Error: not a positive value: " << formatValue(value)
				  << " => " << fmtDate << std::endl;
		return;
	}
	if (value >= 1e3)
	{
		std::cerr << "Error: value too large: " << formatValue(value)
				  << " => " << fmtDate << std::endl;
		return;
	}
	std::cout << fmtDate << " => " << formatValue(value)
			  << " = " << formatValue(exchangeValue()) << std::endl;
}

void BitcoinExchange::parseInput(const std::string &date, const std::string &strValue)
{
	iData.tm = (tm){};
	if (!checkInputFormat(date, strValue))
		return;
	checkInputValue();
}

std::map<time_t, double> BitcoinExchange::_data;

bool BitcoinExchange::_dataLoaded = (BitcoinExchange::loadData(), true);

static bool openData(std::ifstream &ifs, const std::string &data)
{
	ifs.open(data.c_str());
	if (!ifs.is_open())
	{
		std::cerr << "Error: could not open input file" << std::endl;
		return false;
	}
	return true;
}

static bool checkDataDate(const std::string &date, tm *tm)
{
	if (strptime(date.c_str(), "%Y-%m-%d", tm) == NULL)
	{
		std::cerr << "Error: bad date: " << date << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::checkDataValue(const std::string &strValue, tm *tm)
{
	std::istringstream iss(strValue);
	double value;
	if (iss >> value)
		_data[mktime(tm)] = value;
	else
		std::cerr << "Error: bad exchange_rate: " << iss.str() << std::endl;
}

void BitcoinExchange::loadData()
{
	std::ifstream ifs;
	if (!openData(ifs, "data.csv"))
		return;
	std::string line;
	getline(ifs, line);
	while (getline(ifs, line))
	{
		std::istringstream iss(line);
		std::string date;
		getline(iss, date, ',');
		tm tm = {};
		if (checkDataDate(date, &tm))
		{
			std::string strValue;
			getline(iss, strValue);
			checkDataValue(strValue, &tm);
		}
	}
}
