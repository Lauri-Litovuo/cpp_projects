/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:46:40 by llitovuo          #+#    #+#             */
/*   Updated: 2024/08/29 14:33:20 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
	this->_contactCount = 0;
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
	this->_contacts[this->_contactCount] = newContact;
	this->_contactCount++;
	if (this->_contactCount == MAX_COUNT)
	{
		this->_contactCount = 0;
	}
	return (true);
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

bool	PhoneBook::searchContact(void)
{
	std::string input;
	int			index;

	if (this->_contactCount == 0)
	{
		std::cout << "No contacts available. You can add one by typing ADD." << std::endl;
		return (false);
	}
	for (int i = 0; i < this->_contactCount; i++)
	{
		std::cout << i << "|";
		printFormattedString(this->_contacts[i].getFirstName());
		std::cout << "|";
		printFormattedString(this->_contacts[i].getLastName());
		std::cout << "|";
		printFormattedString(this->_contacts[i].getNickName());
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << "Enter the indext of the contact you want to see: ";
	std::cin >> input;
	while (input.length() != 1 || input[0] < '0' || input[0] > '7')
		std::cout << "Invalid input. Please enter a number between 0 and 7." << std::endl;
	index = input[0] - '0';
	if (index >= this->_contactCount)
	{
		std::cout << "Invalid index." << std::endl;
		return (false);
	}
	std::cout << "First name: " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index].getNickName() << std::endl;
	std::cout << "Phone number: " << this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
	return true;
}