#include "Intern.hpp"

Intern::Intern(){
}

Intern::~Intern(){
}

Intern::Intern(Intern const& src){
	*this = src;
}

Intern& Intern::operator=(Intern const& rhs){
	if (this != &rhs)
	{
	}
	return (*this);
}

AForm* Intern::makeForm(std::string formName, std::string target){
	AForm* form;
	try{
		std::string availableForms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
		int i;
		for (i = 0; i < 3; i++)
		{
			if (formName == availableForms[i])
				break;
			if (i == 2)
				throw FormNotFoundException();
		}
		std::cout << "Intern creates" << availableForms[i] << std::endl;
		switch(i)
		{
			case 0:
				form = new PresidentialPardonForm(target);
				break ;
			case 1:
				form = new RobotomyRequestForm(target);
				break ;
			case 2:
				form = new ShrubbberyCreationForm(target);
				break ;
		}
	}catch(const std::exception &e){
		throw;
	}
	return form;
}

const char* Intern::FormNotFoundException::what() const noexcept{
	return "Asked form not found, thus no form was created by intern";
}
