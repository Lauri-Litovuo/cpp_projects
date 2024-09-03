/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:46:40 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/03 16:02:15 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
	this->_contactPosition = 0;
	return ;
}


PhoneBook::~PhoneBook( void )
{
	return ;
}

void getInput(std::string contactInformation, std::string &input)
{
	std::cout << "Enter " << contactInformation;
	std::getline(std::cin >> std::ws, input);
}

bool	PhoneBook::addContact(void)
{
	Contact newContact;
	std::string input;

	getInput("first name: ", input);
	newContact.setFirstName(input);
	getInput("last name: ", input);
	newContact.setLastName(input);
	getInput("nickname: ", input);
	newContact.setNickName(input);
	getInput("phone number: ", input);
	newContact.setPhoneNumber(input);
	getInput("darkest secret: ", input);
	newContact.setDarkestSecret(input);
	this->_contacts[this->_contactPosition] = newContact;
	this->_contactPosition++;
	if (this->_contactPosition == MAX_COUNT)
		this->_contactPosition = 0;
	return (true);
}

void indexQuery(int *index)
{
	std::string input;

	std::cout << "Enter the index of the contact you want to see: ";
	std::cin >> input;
	while (input.length() != 1 || input[0] < '1' || input[0] > '8')
	{
		std::cout << "Invalid input. Please enter a number between 1 and 8." << std::endl;
		std::cout << "Enter the index of the contact you want to see: ";
		std::cin >> input;
	}
	*index = input[0] - '0' - 1;
}

void printFormattedString(std::string str)
{
	if (str.length() > MAX_WIDTH)
	{
		std::cout << str.substr(0, 9) << ".";
	}
	else
	{
		std::cout.width(MAX_WIDTH);
		std::cout << str;
	}
}

void printPhoneBook(Contact contacts[MAX_COUNT], int contactCount)
{
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << i + 1 << "|";
		printFormattedString(contacts[i].getFirstName());
		std::cout << "|";
		printFormattedString(contacts[i].getLastName());
		std::cout << "|";
		printFormattedString(contacts[i].getNickName());
		std::cout << "|";
		std::cout << std::endl;
	}
}

void printContact(Contact *contacts)
{
	std::cout << "First Name: " << contacts->getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts->getLastName() << std::endl;
	std::cout << "Nickname: " << contacts->getNickName() << std::endl;
	std::cout << "Phone Number: " << contacts->getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts->getDarkestSecret() << std::endl;
}

bool	PhoneBook::searchContact(void)
{
	std::string input;
	int			index;
	int			contactCount;

	if (this->_contactPosition == 0 && this->_contacts[0].getFirstName() == "")
	{
		std::cout << "No contacts available. You can add one by typing ADD." << std::endl;
		return (false);
	}
	for (contactCount = 0; contactCount < MAX_COUNT; contactCount++)
	{
		if (this->_contacts[contactCount].getFirstName() == "")
			break;
	}
	printPhoneBook(this->_contacts, contactCount);
	indexQuery(&index); 
	if (index >= contactCount)
	{
		std::cout << "Invalid index. No contact in that field" << std::endl;
		return (false);
	}
	printContact(&this->_contacts[index]);
	return (true);
}
