#pragma once
#include <string>
#include <exception>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const& src);
		PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);

		void execute(Bureaucrat const & executor) const override;
		const std::string getTarget() const;

	private:
		const std::string _target;
};