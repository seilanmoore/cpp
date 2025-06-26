#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <ctime>
#include <map>
#include <fstream>
#include <sstream>

typedef struct sInputData
{
	tm tm;
	double value;
} tInputData;

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const std::string &input);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void printData() const;

private:
	static std::map<time_t, double> _data;
	static bool _dataLoaded;
	sInputData iData;

	static void loadData();
	static void checkDataValue(const std::string &strValue, tm *tm);
	bool openInput(std::ifstream &ifs, const std::string &input) const;
	void parseInput(const std::string &date, const std::string &strValue);
	bool checkInputFormat(const std::string &date, const std::string &strValue);
	void checkInputValue();
	double exchangeValue() const;
};

#endif
