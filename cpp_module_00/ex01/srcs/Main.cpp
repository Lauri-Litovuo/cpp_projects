/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:38:40 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/03 15:38:46 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				continue;
			}
		}
		else if (input == "SEARCH")
		{
			if (!myBook.searchContact())
			{
				continue;
			}
		}
		else if (input == "EXIT")
			break;
	}
	return (0);
}
