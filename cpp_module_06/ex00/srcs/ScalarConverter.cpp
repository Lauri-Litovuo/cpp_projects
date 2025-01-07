#include "ScalarConverter.hpp"

void printTheConversions(char c, int i, float f, double d)
{
	std::cout << "char: ";
	if (isprint(c) && d < 255 && d > 0)
		std::cout << "'" << c << "'" << std::endl;
	else if (d <= 255 && d >= 0)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "int: ";
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || std::isnan(d))
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;

	std::cout << "float: ";
	if (std::isinf(d) && d < 0)
		std::cout << "-inff" << std::endl;
	else if (std::isinf(d) && d > 0)
		std::cout << "inff" << std::endl;
	else if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

bool onlyNumbers(std::string input){
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && !(input[i] == '-' && i == 0))
			return false;
	}
	return true;
}

eType getType(std::string input){

	if (input.length() == 1 && !isdigit(input[0]))
		return CHAR;
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return FLOAT;
	if (input == "-inf" || input == "+inf" || input == "nan")
		return DOUBLE;
	if (onlyNumbers(input))
		return INT;
	if (input.find('.') != std::string::npos)
	{
		std::string noDot = input.erase(input.find('.'), 1);
		if (onlyNumbers(noDot))
			return DOUBLE;
		if (onlyNumbers(noDot.substr(0, noDot.length() - 1)) && noDot[noDot.length() - 1] == 'f')
			return FLOAT;
	}
	return NA;
}

void ScalarConverter::convert(const std::string &input)
{
	char c;
	int i;
	float f;
	double d;

	try {
		switch(getType(input))
		{
			case CHAR:
				c = static_cast<char>(input[0]);
				i = static_cast<int>(c);
				f = static_cast<float>(c);
				d = static_cast<double>(c);
				break;
			case INT:
				i = std::stoi(input);
				c = static_cast<char>(i);
				f = static_cast<float>(i);
				d = static_cast<double>(i);
				break;
			case FLOAT:
				f = std::stof(input);
				c = static_cast<char>(f);
				i = static_cast<int>(f);
				d = static_cast<double>(f);
				break;
			case DOUBLE:
				d = std::stod(input);
				c = static_cast<char>(d);
				i = static_cast<int>(d);
				f = static_cast<float>(d);
				break;
			default:
				std::cout << "Cannot be converted" << std::endl;
				return;
		}
	} catch (const std::invalid_argument& e) {
		std::cout << "Invalid argument: " << e.what() << std::endl;
		return;
	} catch (const std::out_of_range& e) {
		std::cout << "Out of range: " << input << std::endl;
		return;
	}
	printTheConversions(c, i, f, d);
}
