#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>

enum eType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NA
};

class ScalarConverter
{
	public:
		static void convert(const std::string &input);
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter &src) = delete;
		ScalarConverter &operator=(const ScalarConverter &src) = delete;
		~ScalarConverter() = delete;
};