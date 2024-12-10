#pragma once
#include <string>
#include <exception>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubbberyCreationForm : public AForm {
	public:
		ShrubbberyCreationForm();
		ShrubbberyCreationForm(const std::string target);
		~ShrubbberyCreationForm();
		ShrubbberyCreationForm(ShrubbberyCreationForm const& src);
		ShrubbberyCreationForm& operator=(ShrubbberyCreationForm const& rhs);

		void execute(Bureaucrat const & executor) const override;
		const std::string getTarget() const;

	private:
		const std::string _target;
};