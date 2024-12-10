#include "../incl/Bureaucrat.hpp"
#include "../incl/Form.hpp"
#include <iostream>

int main(){
	try{
		Bureaucrat one(2, "josh");
		std::cout << one << std::endl;
		Form form("form", 1);
		std::cout << form << std::endl;
		one.signForm(form);
		std::cout << form << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
