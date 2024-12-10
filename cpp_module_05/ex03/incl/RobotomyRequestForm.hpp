#pragma once
#include <string>
#include <exception>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const& src);
		RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);

		void execute(Bureaucrat const & executor) const override;
		const std::string getTarget() const;

	private:
		const std::string _target;
};