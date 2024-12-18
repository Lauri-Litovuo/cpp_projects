#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void presidentialTest(){
	std::cout << "Testing PresidentialPardonForm class" << std::endl;
	try{
		PresidentialPardonForm form("target");
		std::cout << form << std::endl;
		Bureaucrat bureaucrat(5, "high");
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		}catch(const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	std::cout << "\n";

	//sign failed
	try{
		std::cout << "Checking sign failure" << std::endl;
		PresidentialPardonForm form("target");
		Bureaucrat bureaucrat(150, "lowest");
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		}catch(const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	std::cout << "\n";

	//execute failed
	try{
		std::cout << "Checking execute failure" << std::endl;
		PresidentialPardonForm form("target");
		Bureaucrat bureaucrat(6, "mid");
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		}catch(const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	std::cout << "\n\n\n";
}

void robotomyTest(){
	std::cout << "Testing RobotomyRequestForm class" << std::endl;
	try{
		RobotomyRequestForm form("target");
		Bureaucrat bureaucrat(5, "high");
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		}catch(const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	std::cout << "\n";
	//sign failed
	try{
		std::cout << "Checking sign failure" << std::endl;
		RobotomyRequestForm form("target");
		Bureaucrat bureaucrat(150, "low");
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		}catch(const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	std::cout << "\n";

	//execute failed
	try{
		std::cout << "Checking execute failure" << std::endl;
		RobotomyRequestForm form("target");
		Bureaucrat bureaucrat(46, "mid");
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		}catch(const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	std::cout << "\n";

	//checking randomness
	try{
		std::cout << "Checking randomness" << std::endl;
		RobotomyRequestForm form("target");
		Bureaucrat bureaucrat(5, "high");
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		bureaucrat.executeForm(form);
		bureaucrat.executeForm(form);
		bureaucrat.executeForm(form);
		bureaucrat.executeForm(form);
		}catch(const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	std::cout << "\n\n\n";
}

void shrubberyTest(){
	std::cout << "Testing ShrubbberyCreationForm class\n" << std::endl;
	try{
		ShrubbberyCreationForm form("target");
		Bureaucrat bureaucrat(5, "high");
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		}catch(const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	std::cout << "\n";
	//sign failed
	try{
		std::cout << "Checking sign failure" << std::endl;
		ShrubbberyCreationForm form("target");
		Bureaucrat bureaucrat(150, "low");
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		}catch(const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	std::cout << "\n";
	//execute failed
	try{
		std::cout << "Checking execute failure" << std::endl;
		ShrubbberyCreationForm form("target");
		Bureaucrat bureaucrat(138, "mid");
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		}catch(const std::exception &e){
			std::cerr << e.what() << std::endl;
		}

	std::cout << "\n";
	//checking directory
	try{
		std::cout << "Checking directory" << std::endl;
		ShrubbberyCreationForm form("srcs");
		Bureaucrat bureaucrat(5, "high");
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		}catch(const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	std::cout << "\n\n\n";
}


int main(){
	// testing Aform abstract class
	// std::cout << "Testing AForm abstract class" << std::endl;
	// AForm form("form", 0, 0);

	presidentialTest();
	robotomyTest();
	shrubberyTest();
}
