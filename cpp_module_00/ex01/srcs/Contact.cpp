/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:33:24 by llitovuo          #+#    #+#             */
/*   Updated: 2024/08/29 14:51:33 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>

Contact::Contact(void)
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
	Contact::_counter += 1;
}

Contact::~Contact(void)
{
	Contact::_counter -= 1;
	return ;
}

std::string	Contact::getFirstName() const
{
	return (this->_firstName);
}

std::string	Contact::getLastName() const
{
	return (this->_lastName);
}
std::string	Contact::getNickName() const
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber() const
{
	return(this->_phoneNumber);
}

void	Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}
void Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}
void Contact::setNickName(std::string nickName)
{
	this->_nickname = nickName;
}
void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

int Contact::getCounter() const
{
	return (Contact::_counter);
}

int Contact::_counter = 0;