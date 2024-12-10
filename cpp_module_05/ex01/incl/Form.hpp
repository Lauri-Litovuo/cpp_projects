#pragma once
#include <iomanip>
#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form();
		Form(const std::string name, const int gradeToSign);
		~Form();
		Form(Form const& src);
		Form & operator=(Form const& rhs);

		const std::string getName() const;
		bool getSignState() const;
		int getGradeToSign() const;
		void beSigned(Bureaucrat signer);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const noexcept;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const noexcept;
		};

	private:
		const std::string _name;
		const int _gradeToSign;
		bool _signState;
};

std::ostream & operator<<(std::ostream& os, Form const & rhs);
