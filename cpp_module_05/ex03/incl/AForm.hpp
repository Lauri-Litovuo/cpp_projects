#pragma once
#include <iomanip>
#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm();
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		virtual ~AForm();
		AForm(AForm const& src);
		AForm & operator=(AForm const& rhs);

		const std::string getName() const;
		bool getSignState() const;
		int getGradeToSign() const;
		void beSigned(Bureaucrat signer);
		int getGradeToExecute() const;

		virtual void execute(Bureaucrat const & executor) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const noexcept;
		};

	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _signState;
};

std::ostream & operator<<(std::ostream& os, AForm const & rhs);
