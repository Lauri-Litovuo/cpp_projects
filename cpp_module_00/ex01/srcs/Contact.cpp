/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:33:24 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/03 15:41:05 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Contact.hpp"

Contact::Contact(void)
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

Contact::~Contact(void)
{
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

std::string	Contact::getDarkestSecret() const
{
	return (this->_darkestSecret);
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
