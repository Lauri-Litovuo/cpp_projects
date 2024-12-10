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
	if (formName == "presidential pardon")
		return new PresidentialPardonForm(target);
	else if (formName == "robotomy request")
		return new RobotomyRequestForm(target);
	else if (formName == "shrubbery creation")
		return new ShrubbberyCreationForm(target);
	else
		throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const noexcept{
	return "Form not found";
}
