#pragma once
#include <string>
#include <exception>
#include <iostream>


class Bureaucrat{
	public:
		Bureaucrat();
		Bureaucrat(int grade);
		~Bureaucrat();
		Bureaucrat (Bureaucrat const& src);
		Bureaucrat& operator= (Bureaucrat const& rhs);
		std::string getName(void) const;
		unsigned int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);

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
		const std::string _name = "josh";
		unsigned int _grade;
};


