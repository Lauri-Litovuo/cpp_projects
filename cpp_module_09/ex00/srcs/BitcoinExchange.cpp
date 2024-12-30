#include "BitcoinExchange.hpp"


void BitcoinExchange::_checkDate(std::string date){
	if (date.size() != 10)
		throw InvalidDateException();
	if (date[4] != '-' || date[7] != '-')
		throw InvalidDateException();
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	if (year.find_first_not_of("0123456789") != std::string::npos ||
		month.find_first_not_of("0123456789") != std::string::npos ||
		day.find_first_not_of("0123456789") != std::string::npos)
		throw InvalidDateException();
	try{
		int yearInt = std::stoi(year);
		int monthInt = std::stoi(month);
		int dayInt = std::stoi(day);
		if (yearInt < 2008 || yearInt > 2025 || monthInt < 1 || monthInt > 12 || dayInt < 1 || dayInt > 31)
			throw InvalidDateException();
	} catch (std::exception &e){
		throw InvalidDateException();
	}
	
	
}

BitcoinExchange::BitcoinExchange(const char *filename){
	std::ifstream file;
	file.open(filename);
	if (!file.is_open())
		throw InvalidFileException();
	
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		throw InvalidLineException();
	while(std::getline(file, line))
	{
		std::string date;
		std::string value;
		std::string::size_type pos = line.find("|");
		if (pos == std::string::npos)
			throw InvalidLineException();
		pos = line.find(" ");
		if (pos == std::string::npos) 
			throw InvalidLineException();
		date = line.substr(0, pos);
		try{
			_checkDate(date);
		} catch (std::exception &e){
			throw;
		}
		pos = line.find("|");
		if (pos == std::string::npos || pos == line.size() - 1 || pos == 0) 
			throw InvalidLineException();
		value = line.substr(pos + 1);
		if (value.find_first_not_of("0123456789.") != std::string::npos)
			throw InvalidValueException();

	}
}

BitcoinExchange::~BitcoinExchange(){
}
