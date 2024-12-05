#pragma once
#include <iostream>
#include <string>

class AForm{

	public:

		

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
		const std::string _name;
		bool _signed;
		const unsigned int _gradeToSign;
		const unsigned int _gradeToExcecute;
};
