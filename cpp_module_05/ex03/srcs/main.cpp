#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(){
	Intern intern;
	try{
		AForm *form = intern.makeForm("presidential pardon", "target");
		Bureaucrat bureaucrat(5, "high");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n";
	try{
		AForm *form = intern.makeForm("robotomy request", "target");
		Bureaucrat bureaucrat(5, "high");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n";
	try{
		AForm *form = intern.makeForm("shrubbery creation", "treeees");
		Bureaucrat bureaucrat(5, "high");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n";
	try{
		AForm *form = intern.makeForm("not found", "asdzxc");
		Bureaucrat bureaucrat(5, "high");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n\n\n";
}
