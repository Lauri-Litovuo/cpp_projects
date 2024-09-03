#include <iostream>
#include <string>
#include "../incl/Contact.hpp"
#include "../incl/PhoneBook.hpp"

int main(){
	PhoneBook myBook;
	std::string input;

	while (1)
	{
		std::cout << "Enter ADD, SEARCH or EXIT: ";
		std::cin >> input;
		if (input == "ADD")
		{
			if (!myBook.addContact())
			{
				std::cout << "Error adding contact." << std::endl;
				continue;
			}
		}
		else if (input == "SEARCH")
		{
			if (!myBook.searchContact())
			{
				std::cout << "Error searching contact." << std::endl;
				continue;
			}
		}
		else if (input == "EXIT")
			break;
	}
	return (0);
}
