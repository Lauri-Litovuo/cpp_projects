#include "Bureaucrat.hpp"

int main(){
	try{
		const Bureaucrat *one = new Bureaucrat(15);
		delete one;

	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
