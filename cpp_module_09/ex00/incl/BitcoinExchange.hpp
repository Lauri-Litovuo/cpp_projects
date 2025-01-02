#pragma once
#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <vector>
#include <ctime>
#include <filesystem>

# define DB_PATH "./srcs/data.csv"

enum eError
{
	VALID,
	INVALID_LINE,
	INVALID_DATE,
	INVALID_VALUE,
	INVALID_NEGATIVE_VALUE,
	INVALID_TOO_LARGE_VALUE,
};

struct Bitcoin
{
	std::string line;
	std::string date;
	int year;
	int month;
	int day;
	double value;
	int error;
};

class BitcoinExchange
{
	public:
		BitcoinExchange(const char *filename);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &other);
		void run();
		
		class InvalidFileException : public std::exception
		{
			public:
				virtual const char *what() const noexcept;
		};
		class InvalidLineException : public std::exception
		{
			public:
				virtual const char *what() const noexcept;
		};
		class InvalidDateException : public std::exception
		{
			public:
				virtual const char *what() const noexcept;
		};
		
		class InvalidValueException : public std::exception
		{
			public:
				virtual const char *what() const noexcept;
				virtual int errorCode() const noexcept;
		};
		
		class NegativeValueException : public InvalidValueException
		{
			public:
				virtual const char *what() const noexcept;
				virtual int errorCode() const noexcept;
		};
		class TooLargeValueException : public InvalidValueException
		{
			public:
				virtual const char *what() const noexcept;
				virtual int errorCode() const noexcept;
		};
		class InvalidFirstLineException : public std::exception
		{
			public:
				virtual const char *what() const noexcept;
		};

	private:
		std::vector<Bitcoin> _bitcoins;
		std::vector<Bitcoin> _database;
		void _checkDate(std::string date, int &year, int &month, int &day);
		void _checkValue(std::string value);
		void _validateDB();
		void _checkBitcoinValue(std::string value);
		std::vector<Bitcoin>::iterator _findClosestDate(Bitcoin &bitcoin);
		void _printError(Bitcoin &bitcoin);
};