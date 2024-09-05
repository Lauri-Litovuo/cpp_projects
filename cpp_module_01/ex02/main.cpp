/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:10:43 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/05 10:16:08 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main( void )
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Printing memory addresses:" << std::endl;
	std::cout << "Address of the string: " << &str << std::endl;
	std::cout << "Address of the stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of the stringREF: " << &stringREF << std::endl;

	std::cout << "\nPrinting the value of the strings:" << std::endl;
	std::cout << "Value of the string: " << str << std::endl;
	std::cout << "Value of the stringPTR: " << *stringPTR << std::endl;
	std::cout << "Similar call as others: stringPTR: " << stringPTR << std::endl;
	std::cout << "Value of the stringREF: " << stringREF << std::endl;
	
	return (0);
}