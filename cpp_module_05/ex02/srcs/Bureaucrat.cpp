#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void){
	_grade = 1;
	std::cout << "Bureaucrat " << _name << " with " << _grade << " constructed" << std::endl;
};

Bureaucrat::Bureaucrat(int grade){
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
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

std::string Bureaucrat::getName(void) const{
	return _name;
};

unsigned int Bureaucrat::getGrade(void) const{
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


