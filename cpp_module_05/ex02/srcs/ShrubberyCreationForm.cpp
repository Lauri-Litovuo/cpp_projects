#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <filesystem>

ShrubbberyCreationForm::ShrubbberyCreationForm() : AForm("shrubbery creation", 145, 137), _target("")
{
}

ShrubbberyCreationForm::ShrubbberyCreationForm(const std::string target) : AForm("shrubbery creation", 145, 137), _target(target)
{
}

ShrubbberyCreationForm::~ShrubbberyCreationForm(){
}

ShrubbberyCreationForm::ShrubbberyCreationForm(ShrubbberyCreationForm const& src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()), _target(src.getTarget()){
	*this = src;
}

ShrubbberyCreationForm& ShrubbberyCreationForm::operator=(ShrubbberyCreationForm const& rhs){
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

void ShrubbberyCreationForm::execute(Bureaucrat const & executor) const{
	if(!getSignState())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > 137)
		throw AForm::GradeTooLowException();
	try{
		if(_target.empty() || std::filesystem::is_directory(_target))
			throw std::exception();
		std::ofstream file(_target + "_shrubbery");
		if (!file.is_open())
			throw std::exception();
		file << "      /\\  /\\       " << std::endl;
		file << "     /  \\ / \\      " << std::endl;
		file << "     / \\ / \\       " << std::endl;
		file << "      ||   ||        " << std::endl;
	}catch(const std::exception &e){
		std::cerr << "target could not be opened or is a directory" << std::endl;
	}
}

const std::string ShrubbberyCreationForm::getTarget() const{
	return this->_target;
}

