#include "../incl/Bureaucrat.hpp"
#include <iostream>

int main(){
	try{
		Bureaucrat one(2, "josh");
		std::cout << one << std::endl;
		one.incrementGrade();
		one.decrementGrade();
		one.decrementGrade();

	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
