#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5), _target("")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("presidential pardon", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()), _target(src.getTarget()){
	*this = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs){
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if(!getSignState())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > 5)
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

const std::string PresidentialPardonForm::getTarget() const{
	return this->_target;
}