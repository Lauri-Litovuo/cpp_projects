#include "../incl/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _grade(2), _name(""){
	std::cout << "Bureaucrat " << _name << " with " << _grade << " constructed" << std::endl;
};

Bureaucrat::Bureaucrat(int grade, const std::string name) : _grade(grade), _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat " << _name << " with grade " << _grade << " constructed" << std::endl;
};

Bureaucrat::~Bureaucrat(void){

};

Bureaucrat::Bureaucrat(const Bureaucrat& src){
	*this = src;
};

Bureaucrat& Bureaucrat::operator= (Bureaucrat const& rhs){
	if (this != &rhs)
		_grade = rhs.getGrade();
	return (*this);
};

const std::string Bureaucrat::getName(void) const{
	return this->_name;
};

int Bureaucrat::getGrade(void) const{
	return _grade;
};

void Bureaucrat::incrementGrade(void){
	if (_grade > 1)
	{
		_grade--;
		std::cout << "Grade incremented to " << _grade << std::endl;
	}
	else
		throw GradeTooHighException();
};

void Bureaucrat::decrementGrade(void){
	if (_grade < 150)
	{
		_grade++;
		std::cout << "Grade decremented to " << _grade << std::endl;
	}
	else
		throw GradeTooLowException();
};


const char* Bureaucrat::GradeTooHighException::what() const noexcept{
	return "Bureaucrat's grade too high";
};

const char* Bureaucrat::GradeTooLowException::what() const noexcept{
	return "Bureaucrat's grade too low";
};

std::ostream & operator<<(std::ostream & os, Bureaucrat const & rhs) {
	os << rhs.getName() + ", bureaucrat grade " + std::to_string(rhs.getGrade());
	return os;
}

void Bureaucrat::signForm(AForm& form){
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " could't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form){
	try
	{
		std::cout << _name << " tries to execute " << form.getName() << std::endl;
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const AForm::FormNotSignedException& e)
	{
		std::cerr << _name << " could't execute " << form.getName() << " because " << e.what() << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cerr << _name << " could't execute " << form.getName() << " because " << e.what() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " could't execute " << form.getName() << " because target could not be opened or is a directory" << std::endl;
	}
}
