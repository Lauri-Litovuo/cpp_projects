#pragma once
#include <string>
#include <exception>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat{
	public:
		Bureaucrat();
		Bureaucrat(int grade, const std::string name);
		~Bureaucrat();
		Bureaucrat (Bureaucrat const& src);
		Bureaucrat& operator= (Bureaucrat const& rhs);

		const std::string getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(Form & form);

		class GradeTooHighException : public std::exception
		{
			public:
			virtual const char* what() const noexcept;
		};

		class GradeTooLowException : public std::exception
		{
			public:
			virtual const char* what() const noexcept;
		};

	private:

		int _grade;
		const std::string _name;
};

std::ostream & operator<<(std::ostream& os, Bureaucrat const & rhs);
