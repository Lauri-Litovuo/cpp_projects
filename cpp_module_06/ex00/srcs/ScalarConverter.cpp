#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &input){
	
	
	std::cout << "char: ";
	try{
		
		double d = std::stod(input);
		int i = static_cast<int>(d);

		if (i < 0 || i > 127)
			throw std::exception();
		if (std::isprint(static_cast<char>(i)))
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	} catch (std::exception &e){
		std::cout << "impossible" << std::endl;
	}
	
	std::cout << "int: ";
	try{
		double d = std::stod(input);
		if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min() 
			|| std::isnan(d) || std::isinf(d))
			throw std::exception();
		int i = static_cast<int>(d);
		std::cout << i << std::endl;
	} catch (std::exception &e){
		std::cout << "impossible" << std::endl;
	}
	try{
		std::cout << "float: ";
		float f = std::stof(input);
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	} catch (std::exception &e){
		std::cout << "impossible" << std::endl;
	}
	try{
		std::cout << "double: ";
		double d = std::stod(input);
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	} catch (std::exception &e){
		std::cout << "impossible" << std::endl;
	}
}

