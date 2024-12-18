#include "Form.hpp"

Form::Form() : _name("form"), _gradeToSign(1), _gradeToExecute(1), _signState(false){
};

Form::Form(std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	_signState = false;
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
};

Form::~Form(){
};

Form::Form(Form const& src) : _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	*this = src;
};

Form& Form::operator= (Form const& rhs){
	if (this != &rhs)
	{
		this->_signState = rhs.getSignState();
	}
	return (*this);
};

const std::string Form::getName() const{
	return this->_name;
};

bool Form::getSignState() const{
	return this->_signState;
}

int Form::getGradeToSign() const{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const{
	return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat signer){
	if (_gradeToSign >= signer.getGrade())
		_signState = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const noexcept{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const noexcept{
	return "Grade too low";
}

std::ostream & operator<<(std::ostream& os, Form const & rhs){
	os << "Form " << rhs.getName() << " is ";
	if (rhs.getSignState())
		os << "signed";
	else
		os << "not signed";
	os << " and requires grade " << rhs.getGradeToSign() << " to be signed and " << rhs.getGradeToExecute() << " to be executed.";
	return os;
}
