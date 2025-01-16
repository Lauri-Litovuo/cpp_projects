#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const char *filename){
	if (!std::filesystem::is_regular_file(filename))
		throw InvalidFileException();
	std::ifstream file;
	file.open(filename);
	if (!file.is_open())
		throw InvalidFileException();
	
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
	{
		file.close();
		throw InvalidFirstLineException();
	}
	std::vector<Bitcoin> bitcoins;
	while(std::getline(file, line))
	{
		try{
			std::string date = "";
			std::string value = "";
			//check if the line is valid and get the date and value
			std::string::size_type pos = line.find(" | ");
			try {
				if (pos == std::string::npos)
					throw InvalidLineException();
				pos = line.find(" ");
				if (pos == std::string::npos) 
					throw InvalidLineException();
			} catch (std::exception &e){
				bitcoins.push_back({line,"", 0, 0, 0, 0, eError::INVALID_LINE});
				throw;
			}
			date = line.substr(0, pos);
			try{

				std::string::size_type pos = line.find("|");
				if (pos == std::string::npos || pos == line.size() - 1 || pos == 0) 
					throw InvalidLineException();
				if (line[pos + 1] != ' ')
					throw InvalidLineException();
			} catch (std::exception &e){
				bitcoins.push_back({line,date, 0, 0, 0, 0, eError::INVALID_LINE});
				throw;
			}

			//check if the date is valid
			int year = 0;
			int month = 0;
			int day = 0;
			try{
					_checkDate(date, year, month, day);
			} catch (std::exception &e){
				bitcoins.push_back({line, date, 0, 0, 0, 0, eError::INVALID_DATE});
				throw;
			}
			//check if the value is valid
			value = line.substr(pos + 3);
			try{
				_checkValue(value);
			} catch (InvalidValueException &e){
				bitcoins.push_back({line, date, 0, 0, 0, 0, e.errorCode()});
				throw;
			}
			//add the bitcoin to the vector
			bitcoins.push_back({line, date, year, month, day, std::stod(value), eError::VALID});
		} catch (std::exception &e){
			continue;
		}
	}
	file.close();
	_bitcoins = bitcoins;
}

BitcoinExchange::~BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other){
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other){
	_bitcoins = other._bitcoins;
	return *this;
}


void BitcoinExchange::run(){
	try{
		_validateDB();
	} catch (std::exception &e){
		std::cerr << "Error in database" << std::endl;
		throw ;
	}
	for (std::vector<Bitcoin>::iterator bctIt = _bitcoins.begin(); bctIt != _bitcoins.end(); bctIt++)
	{
		if (bctIt->error == eError::VALID)
		{
			std::vector<Bitcoin>::iterator dbIte = _findClosestDate(*bctIt);
			double totalValue = bctIt->value * dbIte->value;
			std::cout << bctIt->date << " => " << bctIt->value << " = " << totalValue << std::endl;
		}
		else
			_printError(*bctIt);
	}
}



//helper functions

void BitcoinExchange::_printError(Bitcoin &bitcoin){
	switch(bitcoin.error){
		case eError::INVALID_LINE:
			std::cout << "Error: Bad input" << " => "<< bitcoin.line << std::endl;
			break;
		case eError::INVALID_DATE:
			std::cout << "Error: Invalid date" << " => "<< bitcoin.line << std::endl;
			break;
		case eError::INVALID_VALUE:
			std::cout << "Error: Invalid value" << " => "<< bitcoin.line << std::endl;
			break;
		case eError::INVALID_NEGATIVE_VALUE:
			std::cout << "Error: Not a positive number" << " => "<< bitcoin.line << std::endl;
			break;
		case eError::INVALID_TOO_LARGE_VALUE:
			std::cout << "Error: Too large number" << " => "<< bitcoin.line << std::endl;
			break;
		default:
			std::cout << "Error: Unknown error" << " => "<< bitcoin.line << std::endl;
			break;
	}
}

std::vector<Bitcoin>::iterator BitcoinExchange::_findClosestDate(Bitcoin &bitcoin)
{
	long diff = __LONG_MAX__;
	long minDiff = __LONG_MAX__;
	std::vector<Bitcoin>::iterator closest = _database.end();
	for (std::vector<Bitcoin>::iterator it = _database.begin(); it != _database.end(); it++)
	{
		if ((it->year > bitcoin.year)
			|| (it->year == bitcoin.year && it->month > bitcoin.month)
			|| ((it->year == bitcoin.year && it->month == bitcoin.month) && it->day > bitcoin.day))
			return (closest);
		diff = std::abs(it->year - bitcoin.year) * 365 + std::abs(it->month - bitcoin.month) * 30 + std::abs(it->day - bitcoin.day);
		if (diff == 0)
			return (it);
		if (diff < minDiff)
		{
			minDiff = diff;
			closest = it;
		}
	}
	return (closest);
}

void BitcoinExchange::_checkDate(std::string date, int &year_date, int &month_date, int &day_date){
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
		time_t now = time(0);
		const tm* ltm = localtime(&now);
		int yearNow = 1900 + ltm->tm_year;
		int monthNow = 1 + ltm->tm_mon;
		int dayNow = ltm->tm_mday;
		//check if the date is valid, not in the future, and is not a leap year
		if (yearInt < 0 || yearInt > yearNow || monthInt < 1 || monthInt > 12 || dayInt < 1 || dayInt > 31
			|| (yearInt == yearNow && monthInt > monthNow) || (yearInt == yearNow && monthInt == monthNow && dayInt > dayNow)
			|| (yearInt % 4 != 0 && monthInt == 2 && dayInt > 28) || (yearInt % 4 == 0 && monthInt == 2 && dayInt > 29)
			|| ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30))
			throw InvalidDateException();
		year_date = yearInt;
		month_date = monthInt;
		day_date = dayInt;
	} catch (std::exception &e){
		throw;
	}
}

void BitcoinExchange::_checkValue(std::string value){
	if (value.find("-") != std::string::npos && value.find("-") == 0)
		throw NegativeValueException();
	if (value.find_first_not_of("0123456789.") != std::string::npos)
		throw InvalidValueException();
	if (value.find(".") != std::string::npos)
	{
		std::string::size_type pos = value.find(".");
		if (pos == value.size() - 1)
			throw InvalidValueException();
		if (value.find(".", pos + 1) != std::string::npos)
			throw InvalidValueException();
	}
	try{
		double valueDouble = std::stod(value);
		if (valueDouble < 0)
			throw NegativeValueException();
		if (valueDouble > 1000)
			throw TooLargeValueException();
	} catch (std::exception &e){
		throw;
	}
}

void BitcoinExchange::_validateDB(){
	std::ifstream file;
	file.open(DB_PATH);
	if (!file.is_open())
		throw InvalidFileException();
	if (file.peek() == std::ifstream::traits_type::eof())
	{
		file.close();
		throw InvalidFirstLineException();
	}
	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
	{
		file.close();
		throw InvalidFirstLineException();
	}
	std::vector<Bitcoin> database;
	while(std::getline(file, line))
	{
		std::string date = "";
		std::string value = "";
		int year = 0;
		int month = 0;
		int day = 0;
		std::string::size_type pos = 0;
		try{
			pos = line.find(",");
			if (pos == std::string::npos || pos == line.size() - 1 || pos == 0)
				throw InvalidLineException();
			date = line.substr(0, pos);
			_checkDate(date, year, month, day);
			value = line.substr(pos + 1);
			_checkBitcoinValue(value);
		} catch (std::exception &e){
			file.close();
			throw ;
		}
		database.push_back({line, date, year, month, day, std::stod(value), eError::VALID});
	}
	file.close();
	_database = database;
}

void BitcoinExchange::_checkBitcoinValue(std::string value){
	if (value.find("-") != std::string::npos && value.find("-") == 0)
		throw NegativeValueException();
	if (value.find_first_not_of("0123456789.") != std::string::npos)
		throw InvalidValueException();
	if (value.find(".") != std::string::npos)
	{
		std::string::size_type pos = value.find(".");
		if (pos == value.size() - 1)
			throw InvalidValueException();
		if (value.find(".", pos + 1) != std::string::npos)
			throw InvalidValueException();
	}
	try{
		double valueDouble = std::stod(value);
		if (valueDouble < 0)
			throw NegativeValueException();
		if (valueDouble > 120000)
			throw TooLargeValueException();
	} catch (std::exception &e){
		throw;
	}
}


const char *BitcoinExchange::InvalidFileException::what() const noexcept{
	return "Error: Invalid file";
}

const char *BitcoinExchange::InvalidLineException::what() const noexcept{
	return "Error: Invalid line";
}

const char *BitcoinExchange::InvalidDateException::what() const noexcept{
	return "Error: Invalid date";
}

const char *BitcoinExchange::NegativeValueException::what() const noexcept{
	return "Error: Negative value";
}

int BitcoinExchange::NegativeValueException::errorCode() const noexcept{
	return eError::INVALID_NEGATIVE_VALUE;
}

const char *BitcoinExchange::InvalidValueException::what() const noexcept{
	return "Error: Invalid value";
}

int BitcoinExchange::InvalidValueException::errorCode() const noexcept{
	return eError::INVALID_VALUE;
}

const char *BitcoinExchange::TooLargeValueException::what() const noexcept{
	return "Error: Value too large";
}

int BitcoinExchange::TooLargeValueException::errorCode() const noexcept{
	return eError::INVALID_TOO_LARGE_VALUE;
}

const char *BitcoinExchange::InvalidFirstLineException::what() const noexcept{
	return "Error: Invalid first line. The first line should be 'date | value'";
}




