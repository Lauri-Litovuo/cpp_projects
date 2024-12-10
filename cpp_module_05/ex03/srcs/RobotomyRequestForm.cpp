#include "RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45), _target("")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("robotomy request", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()), _target(src.getTarget()){
	*this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs){
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if(!getSignState())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > 45)
		throw AForm::GradeTooLowException();
	std::cout << "*drilling noises*" << std::endl;
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1);
	if (dis(gen))
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}

const std::string RobotomyRequestForm::getTarget() const{
	return this->_target;
}
