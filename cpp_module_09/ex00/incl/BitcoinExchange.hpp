#pragma once
#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <vector>

struct Bitcoin
{
	std::string date;
	double value;
};

class BitcoinExchange
{
	public:
		BitcoinExchange(const char *filename);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &other);
		void run();
		
		class NegativeValueException : public std::exception
		{
			public:
				virtual const char *what() const noexcept;
		};
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
		};

	private:
		std::vector<Bitcoin> _bitcoins;
		void _checkDate(std::string date);

};