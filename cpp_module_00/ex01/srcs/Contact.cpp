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

std::string	Contact::getFirstName()
{
	return (this->firstName);
}

std::string	Contact::getLastName()
{
	return (this->lastName);
}
std::string	Contact::getNickName()
{
	return (this->nickname);
}

std::string	Contact::getPhoneNumber()
{
	return(this->phoneNumber)
}
