#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _gradeToSign(1), _gradeToExecute(1),_signState(false)
{
};

AForm::AForm(std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	_signState = false;
	if (gradeToSign > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1)
		throw GradeTooHighException();
};

AForm::~AForm(){
};

AForm::AForm(AForm const& src) : _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src._gradeToExecute)
{
	*this = src;
};

AForm& AForm::operator= (AForm const& rhs){
	if (this != &rhs)
	{
		this->_signState = rhs.getSignState();
	}
	return (*this);
};

const std::string AForm::getName() const{
	return this->_name;
};

bool AForm::getSignState() const{
	return this->_signState;
}

int AForm::getGradeToSign() const{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const{
	return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat signer){
	if (_gradeToSign >= signer.getGrade())
		_signState = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const noexcept{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const noexcept{
	return "Grade too low";
}

const char *AForm::FormNotSignedException::what() const noexcept{
	return "Form not signed";
}

std::ostream & operator<<(std::ostream& os, AForm const & rhs){
	os << "AForm " << rhs.getName() << " is ";
	if (rhs.getSignState())
		os << "signed";
	else
		os << "not signed";
	os << " and requires grade " << rhs.getGradeToSign() << " to be signed and " << rhs.getGradeToExecute() << " to be executed.";
	return os;
}
