#include "Form.hpp"

Form::Form() : _name("form"), _gradeToSign(1), _signState(false){
};

Form::Form(std::string name, const int gradeToSign) : _name(name), _gradeToSign(gradeToSign)
{
	_signState = false;
	if (gradeToSign > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1)
		throw GradeTooHighException();
};

Form::~Form(){
};

Form::Form(Form const& src) : _name(src.getName()), _gradeToSign(src.getGradeToSign())
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
	os << " and requires grade " << rhs.getGradeToSign() << " to be signed";
	return os;
}
