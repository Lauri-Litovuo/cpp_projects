/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:02:13 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/06 10:38:46 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "Levels.hpp"


Levels getLevel(const std::string& input)
{
	if (input == "DEBUG")
		return Levels::DEBUG;
	else if (input == "INFO")
		return Levels::INFO;
	else if (input == "WARNING")
		return Levels::WARNING;
	else if (input == "ERROR")
		return Levels::ERROR;
	else
		return Levels::UNKNOWN;
}


int main(int ac, char **av)
{
	Harl harl;
	Levels level;
	
	if (ac != 2)
	{
		std::cout << "Single argument needed." << std::endl;
		return (1);
	}
	level = getLevel(std::string(av[1]));
	switch (level)
	{
		case Levels::DEBUG:
			harl.complain("DEBUG");
			[[fallthrough]];
		case Levels::INFO:
			harl.complain("INFO");
			[[fallthrough]];
		case Levels::WARNING:
			harl.complain("WARNING");
			[[fallthrough]];
		case Levels::ERROR:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "Unknown complaint." << std::endl;
			break;
	}
	return (0);
}