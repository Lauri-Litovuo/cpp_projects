#pragma once
#include <iomanip>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
	public:
		Form();
		Form(const std::string name, const int gradeToSign);
		~Form();
		Form(Form const& src);
		Form & operator=(Form const& rhs);

		const std::string getName() const;
		bool getSignState() const;
		const int getGradeToSign() const;
		void beSigned(Bureaucrat);

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
